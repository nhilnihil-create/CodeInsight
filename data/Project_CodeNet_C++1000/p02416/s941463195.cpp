#include <iostream>
#include <string>

int main()
{
    while (true) {
        std::string in_str;
        std::cin >> in_str;

        if (in_str.at(0) == '0'){
            break;
        }

        int sum = 0;
        for (size_t i = 0; i < in_str.size(); i++){
            if (in_str.at(i) == '\0'){
                break;
            }

            int in_num = in_str.at(i) - '0';
            sum += in_num;
        }

        std::cout << sum << std::endl;
    }

    return 0;
}