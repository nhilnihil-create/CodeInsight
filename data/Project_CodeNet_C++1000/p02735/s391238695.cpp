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

lint shortest_path(lint i, lint j, lint h, lint w, const std::vector<std::vector<lint>> &maze, std::vector<std::vector<lint>> &memo)
{

    if (memo[i][j] >= 0)
    {
        return memo[i][j];
    }

    if (i == h - 1 && j == w - 1)
    {
        return 0;
    }

    lint down = 201;
    lint right = 201;

    if (i + 1 < h)
    {
        down = shortest_path(i + 1, j, h, w, maze, memo);
        if (maze[i][j] == 1 && maze[i + 1][j] == 0)
        {
            down++;
        }
    }
    if (j + 1 < w)
    {
        right = shortest_path(i, j + 1, h, w, maze, memo);
        if (maze[i][j] == 1 && maze[i][j + 1] == 0)
        {
            right++;
        }
    }

    lint out = std::min(down, right);
    memo[i][j] = out;

    return out;
}

int main()
{
    lint h, w;
    scanf("%lld", &h);
    scanf("%lld", &w);

    std::vector<std::vector<lint>> maze(h, std::vector<lint>(w, 0));

    for (int i = 0; i < h; ++i)
    {
        std::string s;
        std::cin >> s;

        for (int j = 0; j < w; ++j)
        {
            if (s[j] == '.')
            {
                maze[i][j] = 1;
            }
        }
    }

    std::vector<std::vector<lint>> memo(h, std::vector<lint>(w, -1));

    lint ans = shortest_path(0, 0, h, w, maze, memo);

    if (maze[0][0] == 0)
        ans++;

    printf("%lld", ans);

    return 0;
}
