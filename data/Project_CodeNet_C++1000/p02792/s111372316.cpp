#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int gettop(int a)
{
    while( a >= 10 ) a /= 10;
    return a;
}

int main()
{
    int n;
    cin >> n;
    int c[10][10];
    rep(k, 10)
        rep(l, 10) c[k][l] = 0;
        
    for(int i = 1; i <= n; i++)
    {
        c[gettop(i)][i % 10]++;
    }
    _LL ans = 0;
    rep(k, 10)
        rep(l, 10) 
        {
            ans += c[k][l] * c[l][k];
        }

    cout << ans;
    return 0;    
}
