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
    lint n, k;
    scanf("%lld", &n);
    scanf("%lld", &k);

    std::string s;
    std::cin >> s;

    lint base = 0;

    char cur = '0';

    for (int i = 0; i < n; ++i)
    {
        if (cur == s[i])
        {
            base++;
        }
        cur = s[i];
    }

    lint change_num = 0;

    cur = s[0];

    lint change_flag = -1;
    lint ans = base;

    for (int i = 1; i < n; ++i)
    {
        if (cur != s[i])
        {
            change_flag *= (-1);
            if (change_flag < 0)
            {
                ans += 2;
                change_num++;
            }
        }
        cur = s[i];
        if (change_num == k)
        {
            break;
        }
    }

    if (change_num != k && s.front() != s.back())
    {
        ans++;
    }

    std::cout << ans << "\n";
    return 0;
}
