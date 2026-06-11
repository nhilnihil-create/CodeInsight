#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long
#define rep(i, n) for(_LL i = 0; i < (_LL)(n); i++)

int main()
{
    _LL n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    _LL dist = 1;
    _LL c = 0;
    pair<_LL, _LL>* info = new pair<_LL, _LL>[n+1];
    info[0] = make_pair(0, 0);
    for( c = 0; dist <= n; c++ )
    {
        if( c >= dist )
        {
            cout << -1 << endl;
            return 0;
        }
        if( s[c] == '1' ) continue;
        for( _LL l = dist; l <= c + m && dist <= n; l++)
        {
            info[dist++] = make_pair(info[c].first + 1, c);
        }
    }
    c = n;
    _LL* ans = new _LL[info[n].first + 1];
    while( c > 0 )
    {
        ans[info[c].first] = c - info[c].second;
        c = info[c].second;
    }
    for( _LL i = 1; i <= info[n].first; i++ )
    {
        cout << ans[i] << " ";
    }
}