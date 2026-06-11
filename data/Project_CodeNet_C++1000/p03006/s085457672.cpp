#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <numeric>
using lint = long long;

int main()
{

    lint n;
    scanf("%lld", &n);

    std::vector<std::pair<lint, lint>> balls(n);

    for (int i = 0; i < n; ++i)
    {
        lint x, y;
        scanf("%lld", &x);
        scanf("%lld", &y);

        balls[i] = std::make_pair(x, y);
    }

    std::map<std::pair<lint, lint>, lint> dict;

    for (auto ball1 = balls.begin(); ball1 != (balls.end() - 1); ball1++)
    {
        for (auto ball2 = ball1 + 1; ball2 != balls.end(); ball2++)
        {
            lint x_dif = ball1->first - ball2->first;
            lint y_dif = ball1->second - ball2->second;
            if (x_dif < 0)
            {
                x_dif *= -1;
                y_dif *= -1;
            }
            else if (x_dif == 0)
            {
                y_dif = abs(y_dif);
            }
            auto cur_pair = std::make_pair(x_dif, y_dif);
            if (dict.find(cur_pair) == dict.end())
            {
                dict[cur_pair] = 1;
            }
            else
            {
                dict[cur_pair] += 1;
            }
        }
    }

    lint max_step = 0;

    for (auto step = dict.begin(); step != dict.end(); step++)
    {
        if (step->second > max_step)
        {
            max_step = step->second;
        }
    }

    printf("%lld", n - max_step);

    return 0;
}
