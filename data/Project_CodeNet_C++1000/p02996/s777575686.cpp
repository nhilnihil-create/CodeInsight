#include<iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>

struct Data
{
    int A;
    int B;
};


int main()
{
    int N;
    std::cin >> N;
    std::vector<Data> data(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> data[i].A >> data[i].B;
    }

    std:sort(data.begin(), data.end(), [](auto const& lhs, auto const& rhs) {
        return lhs.B > rhs.B; // 左の方が大きい...というイメージ。
    });

    int res = data[0].B;
    for (int i = 0; i < N; i++)
    {
        res = std::min(res, data[i].B);
        res = res - data[i].A;
        //printf("A=%d, B=%d, res=%d\n", data[i].A, data[i].B, res);

        if (res < 0)
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
 
    return 0;
}