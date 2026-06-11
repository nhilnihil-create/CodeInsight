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

    lint h, w;
    scanf("%lld", &h);
    scanf("%lld", &w);

    std::vector<std::vector<lint>> maze(h, std::vector<lint>(w, 0));
    std::vector<std::vector<lint>> lit_h(h, std::vector<lint>(w, 0));
    std::vector<std::vector<lint>> lit_v(h, std::vector<lint>(w, 0));

    for (int i = 0; i < h; ++i)
    {
        std::string s;
        std::cin >> s;

        for (int j = 0; j < w; ++j)
        {
            if (s[j] == '#')
                maze[i][j] = 1;
        }
    }

    for (int i = 0; i < h; ++i)
    {
        lint stream = 0;
        std::vector<lint> write_cells;
        for (int j = 0; j <= w; ++j)
        {
            if (j == w || maze[i][j] == 1)
            {
                for (auto write = write_cells.begin(); write != write_cells.end(); write++)
                {
                    lit_h[i][*write] = stream;
                }
                stream = 0;
                write_cells.clear();
            }
            else
            {
                stream++;
                write_cells.push_back(j);
            }
        }
    }

    for (int j = 0; j < w; ++j)
    {
        lint stream = 0;
        std::vector<lint> write_cells;
        for (int i = 0; i <= h; ++i)
        {
            if (i == h || maze[i][j] == 1)
            {
                for (auto write = write_cells.begin(); write != write_cells.end(); write++)
                {
                    lit_v[*write][j] = stream;
                }
                stream = 0;
                write_cells.clear();
            }
            else
            {
                stream++;
                write_cells.push_back(i);
            }
        }
    }

    lint ans = 0;

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            lint cand = lit_h[i][j] + lit_v[i][j] - 1;
            ans = std::max(ans, cand);
        }
    }

    printf("%lld", ans);

    return 0;
}
