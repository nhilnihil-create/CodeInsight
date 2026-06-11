#include <iostream>
#include <vector>
int main()
{

    int numofTimes = 0;
    std::vector<int> input;
    std::cin >> numofTimes;
    for (int i = 0; i < numofTimes; i++)
    {
        int num;
        std::cin >> num;
        input.push_back(num);
    }
    bool flag;
    for (size_t i = 0; i < input.size(); i++)
    {
        flag = input[i] != i + 1;
        if (flag)
        {
            int temp = input[i];
            input[i] = input[temp - 1];
            input[temp - 1] = temp;
            break;
        }
    }

    for (size_t i = 0; i < input.size() - 1; i++)
    {
        if (input[i] + 1 != input[i + 1])
        {
            std::cout << "NO";
            return 0;
        }
    }

    std::cout << "YES";

    return 0;
}