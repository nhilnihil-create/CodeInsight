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

auto divs(lint x)
{
    std::vector<lint> out;
    lint num = 1;

    while (num < sqrt(x) + 0.01)
    {
        if (x % num == 0)
        {
            if (x / num == num)
            {
                out.push_back(num);
            }
            else if (x / num > num)
            {
                out.push_back(num);
                out.push_back(x / num);
            }
        }
        num++;
    }

    std::sort(ALL(out));

    return out;
}

int main()
{
    lint n;
    scanf("%lld", &n);

    auto divs_n = divs(n);

    std::set<lint> ans;

    for (auto div : divs_n)
    {
        if (div == 1)
            continue;
        lint ncp = n;
        if ((ncp - 1) % div == 0)
        {
            ans.insert(div);
            continue;
        }
        while ((ncp % div) == 0)
        {
            ncp /= div;
            if ((ncp - 1) % div == 0)
            {
                ans.insert(div);
                break;
            }
        }
    }

    auto divs_mk = divs(n - 1);

    for (auto div : divs_mk)
    {
        if (div == 1)
            continue;
        ans.insert(div);
    }

    std::cout << ans.size() << "\n";

    return 0;
}
