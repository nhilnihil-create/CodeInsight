#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

int main(){
    std::vector<std::vector<int>> a(3, std::vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> a[i][j];
        }        
    }
    int n;
    std::cin >> n;
    std::vector<std::vector<bool>> flag(3, std::vector<bool>(3));
    
    for (int i = 0; i < n; i++)
    {
        int b;
        std::cin >> b;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == b)
                {
                    flag[i][j] = true;
                }
            }
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (flag[i][0] && flag[i][1] && flag[i][2])
        {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (flag[0][j] && flag[1][j] && flag[2][j])
        {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    if ((flag[0][0] && flag[1][1] && flag[2][2]) || (flag[2][0] && flag[1][1] && flag[0][2]))
    {
        std::cout << "Yes" << std::endl;
        return 0;
    }

    std::cout << "No" << std::endl;

    return 0;
}