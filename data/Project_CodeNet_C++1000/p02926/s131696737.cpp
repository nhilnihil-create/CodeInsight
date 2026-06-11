//#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <utility>
#define N 120
using namespace std;

pair<int, int> a[N];

int main(void)
{
    int n;
    int i, k, x, y;
    long long o;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d %d", &a[i].first, &a[i].second);

    for(k = o = 0; k < 100000; k ++)
    {
        random_shuffle(a, a + n);
        x = y = 0;
        for(i = 0; i < n; i ++) {
            if((long long)(x + a[i].first) * (x + a[i].first) + (long long)(y + a[i].second) * (y + a[i].second) > (long long)x * x + (long long)y * y)
            {
                x += a[i].first ;
                y += a[i].second;
            }
        }
        o = max(o, (long long)x * x + (long long)y * y);
    }
    printf("%.15Lf\n", sqrt((long double)o));

    return 0;
}
