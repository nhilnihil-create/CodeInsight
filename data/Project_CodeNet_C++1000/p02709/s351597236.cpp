#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)

_LL dp[2004][2004];

int main()
{
    _LL n;
    cin >> n;
    pair<_LL, _LL> *a = new pair<_LL, _LL>[n];
    rep(i, n)
    {
        cin >> a[i].first;
        a[i].second = i;
    } 
    sort(a, a + n, greater<pair<_LL, _LL>>());
    dp[0][0] = 0;
    _LL best = 0;
    rep(i, n)
    {
        int xy = i + 1;
//        cout << i << ":" << a[i].first << "," << a[i].second << endl;
        rep(x, xy + 1)
        {
            _LL y = xy - x;
            dp[x][y] = 0;
            if( x > 0 ) dp[x][y] = max(dp[x][y], dp[x - 1][y] + a[i].first * abs( a[i].second - x + 1));
            if( y > 0 ) dp[x][y] = max(dp[x][y], dp[x][y - 1] + a[i].first * abs( n - y - a[i].second)); 
//            cout << x << "," << y << ":" << dp[x][y] << endl;
            best = max(best, dp[x][y]);
        }
    }
    cout << best << endl;
    delete a;
}