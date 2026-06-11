#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
    string s; cin >> s;
    _LL pre[2];
    _LL next[2];
    pre[0] = 0; pre[1] = 10;
    _LL l = s.length();
    rep(i, l)
    {
        _LL t = s[l - 1 - i] - '0';
        next[0] = min(pre[0] + t, pre[1] + t + 1);
        next[1] = min(pre[0] + abs(10 - t), pre[1] + abs(10 - t - 1));
        swap(pre, next);
    } 
    cout << min( pre[0], pre[1] + 1);
}