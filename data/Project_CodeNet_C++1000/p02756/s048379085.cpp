#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)

int main()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    int l = q * 2 + s.length();
    char *ans = new char[l];
    rep(i,s.length()) ans[q+i] = s[i];
    int d = 1;
    int starti = q;
    int endi = q + s.length();
    rep(t, q)
    {
        int code;
        cin >> code;
        if( code == 1 )
        {
            d = -d;
        }
        else
        {
            int f;
            char c;
            cin >> f >> c;
            int dt = ( f == 1) ? -1 : 1;
            dt *= d;
            if( dt < 0 )
            {
                ans[starti - 1] = c;
                starti--;
            }
            else
            {
                ans[endi] = c;
                endi++;
            }
        }
    }
    if( d > 0 )
    {
        rep(i, endi - starti) cout << ans[starti + i];
    }
    else
    {
        rep(i, endi - starti) cout << ans[endi - 1 - i];        
    }
}