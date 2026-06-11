#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <functional>
#define N 2020
using namespace std;

pair<int, int> a[N];
long long f[N][N];

int main(void)
{
    int n;
    int i, j;

    cin >> n;
    for(i = 1; i <= n; i ++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1, greater<pair<int, int> >());

    for(i = 1; i <= n; i ++)
        for(j = 0; j <= i; j ++)
        {
            if(j)
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + (long long)a[i].first * (a[i].second - j));
            if(i - j)
                f[i][j] = max(f[i][j], f[i - 1][j] + (long long)a[i].first * (n + 1 - (i - j) - a[i].second));
        }
    cout << *max_element(f[n], f[n] + n + 1) << endl;

    return 0;
}
