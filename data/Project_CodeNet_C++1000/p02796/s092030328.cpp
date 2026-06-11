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

bool compare_robots(const std::pair<lint, lint> &left, const std::pair<lint, lint> &right)
{
    return (left.first - left.second) < (right.first - right.second);
}

int main()
{
    lint n;
    std::vector<std::pair<lint, lint>> robots;

    scanf("%lld", &n);

    for (size_t i = 0; i < n; i++)
    {
        lint x, l;
        scanf("%lld", &x);
        scanf("%lld", &l);
        robots.push_back(std::make_pair(x, l));
    }

    std::sort(robots.begin(), robots.end(), compare_robots);

    auto pivot = robots.begin();
    lint ans = robots.size();

    for (auto next = robots.begin() + 1; next != robots.end(); next++)
    {

        if (next->first - next->second < pivot->first + pivot->second)
        {
            ans--;
            if (next->first + next->second < pivot->first + pivot->second)
            {
                pivot = next;
            }
        }
        else
        {
            pivot = next;
        }
    }

    printf("%lld", ans);

    return 0;
}
