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

int main()
{
    lint n, m;

    scanf("%lld", &n);
    scanf("%lld", &m);

    lint inf = 1e9;

    lint pat_num = 1 << n;

    std::vector<lint> key_pat(pat_num, inf);
    key_pat[0] = 0;

    for (int i = 0; i < m; ++i)
    {
        lint a, b;
        scanf("%lld", &a);
        scanf("%lld", &b);

        lint key = 0;
        for (int j = 0; j < b; ++j)
        {
            lint c;
            scanf("%lld", &c);
            key += 1 << (c - 1);
        }

        for (int j = 0; j < pat_num; ++j)
        {
            lint next = j | key;
            if (next == j)
            {
                continue;
            }
            else if (key_pat[j] + a < key_pat[next])
            {
                key_pat[next] = key_pat[j] + a;
            }
        }
    }

    if (key_pat.back() == inf)
    {
        std::cout << -1 << "\n";
    }
    else
    {
        std::cout << key_pat.back() << "\n";
    }

    return 0;
}
