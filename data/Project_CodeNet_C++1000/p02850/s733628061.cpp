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
using lint = long long;

int main()
{
    int n;

    scanf("%d", &n);

    std::vector<std::vector<std::pair<int, int>>> tree(n);
    std::vector<int> edge_color(n - 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);

        tree[a - 1].push_back(std::make_pair(b - 1, i));
        tree[b - 1].push_back(std::make_pair(a - 1, i));
    }

    int k = 0;

    for (int i = 0; i < n; ++i)
    {
        int edge_num = tree[i].size();
        if (k < edge_num)
        {
            k = edge_num;
        }
    }

    std::vector<int> seen(n, 0);
    std::deque<std::pair<int, int>> q;

    q.push_back(std::make_pair(0, 0));
    seen[0] = 1;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop_front();

        int color_cand = 1;
        int prev_color = cur.second;

        for (auto next = tree[cur.first].begin(); next != tree[cur.first].end(); next++)
        {
            if (!seen[next->first])
            {
                if (color_cand == prev_color)
                {
                    color_cand++;
                }
                edge_color[next->second] = color_cand;
                q.push_back(std::make_pair(next->first, color_cand));
                seen[next->first] = 1;
                color_cand++;
            }
        }
    }

    std::cout << k << "\n";

    for (int i = 0; i < n - 1; ++i)
    {
        printf("%d\n", edge_color[i]);
    }

    return 0;
}
