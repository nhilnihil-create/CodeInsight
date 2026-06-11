#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
    int n; cin >> n;
    vector<int> b(n);
    rep(i, n - 1) cin >> b[i];
    _LL ans = 0;
    rep(i, n)
    {
        if( i == 0 )
        {
            ans += b[i];
        }
        else if( i == n - 1)
        {
            ans += b[i - 1];
        }
        else
        {
            ans += min(b[i], b[i - 1]);
        }
    }
    cout << ans << endl;
    return 0;    
}