#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, m, v, p, a[100001];
bool cmp(long long x, long long y)
{
    return x > y;
}
int main(int argc, char const *argv[])
{
    scanf("%lld%lld%lld%lld", &n, &m, &v, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    long long ans = p, sum = 0;
    for (int i = p + 1; i <= n; i++)
    {
        if (a[i] + m < a[p])
        {
            break;
        }
        if (v - n + i <= p)
        {
            ans++;
        }
        else
        {
            if (((v - p - n + i) * m - sum - 1) / (i - p) + 1 + a[p] <= a[i] + m)
            {
                ans++;
            }
        }
        sum += a[p] - a[i];
    }
    printf("%lld\n", ans);
    return 0;
}