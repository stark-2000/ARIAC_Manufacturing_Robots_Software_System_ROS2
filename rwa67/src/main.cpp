#include "rwa67/floor_robot.hpp"

// ================================
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto floor_robot_node = std::make_shared<FloorRobot>();
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(floor_robot_node);

    try {
        executor.spin();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        executor.cancel();
        rclcpp::shutdown();
    }


    

    
    
    
}

// ================================
// int main(int argc, char *argv[])
// {
//     rclcpp::init(argc, argv);
//     auto floor_robot_node = std::make_shared<FloorRobot>();

//     // get demo parameter
//     rclcpp::Parameter demo_param;
//     floor_robot_node->get_parameter("demo", demo_param);

//     rclcpp::executors::MultiThreadedExecutor executor;
//     executor.add_node(floor_robot_node);

//     // if demo is "full"
//     if (demo_param.as_string() == "cpp")
//     {
//         std::thread([&executor]()
//                     { executor.spin(); })
//             .detach();

//         // start the competition
//         floor_robot_node->start_competition_();
//         // move the robot to home pose
//         floor_robot_node->go_home_();
//         // complete orders
//         floor_robot_node->complete_orders_();
//         // end the competition
//         floor_robot_node->end_competition_();
//     }
//     else{
//         executor.spin();
//     }

//     rclcpp::shutdown();
// }