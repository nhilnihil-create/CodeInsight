#include <iostream>
#include <string.h>

int main()
{
    char main_string[1000], sub_string[1000];
    std::cin >> main_string;
    std::cin >> sub_string;

    int difference = strlen(main_string) - strlen(sub_string) + 1;
    int max_same_char[difference];
    for (int i = 0; i < difference; i++)
    {
        max_same_char[i] = 0;
        for (int j = i; j < i + strlen(sub_string); j++)
        {
            if (strncmp(&main_string[j], &sub_string[j - i], 1) == 0)
            {
                //if(main_string[j]==sub_string[j]){
                max_same_char[i]++;
            }
        }
        //std::cout << max_same_char[i] << std::endl;
    }
    int max_num = 0;
    for (int i = 0; i < difference; i++)
    {
        if (max_same_char[i] > max_num)
        {
            max_num = max_same_char[i];
        }
    }
    std::cout << strlen(sub_string) - max_num << std::endl;
    return 0;
}