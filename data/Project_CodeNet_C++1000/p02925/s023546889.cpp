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
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
#define ALL(X) X.begin(), X.end()
using lint = long long;
template <typename T>
void print_container(std::vector<T> vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

std::pair<lint, lint> asc_pair(lint i, lint j)
{
    return std::make_pair(std::min(i, j), std::max(i, j));
}

int main()
{
    lint n;
    scanf("%lld", &n);

    std::vector<std::vector<lint>> match(n, std::vector<lint>(n - 1));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            lint tmp;
            scanf("%lld", &tmp);
            match[i][j] = tmp - 1;
        }
    }

    std::set<std::pair<lint, lint>> waiting;
    std::vector<std::pair<lint, lint>> new_match;

    std::vector<lint> done(n, 0);

    lint done_num = 0;

    for (lint i = 0; i < n; ++i)
    {
        lint cur_match = done[i];
        lint op = match[i][cur_match];
        auto p = asc_pair(i, op);
        new_match.push_back(p);
    }

    lint days = 0;

    while (done_num < n)
    {
        // for (auto p : new_match)
        // {
        //     std::cout << p.first << " " << p.second << "\n";
        // }
        // std::cout << "---"
        //           << "\n";

        // for (auto p : waiting)
        // {
        //     std::cout << p.first << " " << p.second << "\n";
        // }
        // std::cout << "------"
        //           << "\n";
        if (new_match.empty())
        {
            std::cout << -1 << "\n";
            return 0;
        }

        std::vector<std::pair<lint, lint>> next_new_match;
        for (auto p : new_match)
        {
            if (waiting.find(p) == waiting.end())
            {
                waiting.insert(p);
            }
            else
            {
                lint f = p.first;
                lint s = p.second;
                done[f]++;
                done[s]++;
                // std::cout << "done f " << done[f] << "\n";
                if (done[f] != n - 1)
                {
                    lint cur_match = done[f];
                    lint op = match[f][cur_match];
                    next_new_match.push_back(asc_pair(f, op));
                }
                else
                {
                    done_num++;
                }
                // std::cout << "done s " << done[s] << "\n";
                if (done[s] != n - 1)
                {
                    lint cur_match = done[s];
                    lint op = match[s][cur_match];
                    next_new_match.push_back(asc_pair(s, op));
                }
                else
                {
                    done_num++;
                }
                waiting.erase(p);
            }
        }
        new_match = next_new_match;
        days++;
    }

    std::cout << days << "\n";

    return 0;
}
