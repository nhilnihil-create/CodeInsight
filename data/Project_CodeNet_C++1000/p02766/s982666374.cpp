#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _LL long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    _LL n, k;
    cin >> n >> k;
    _LL kt = k;
    _LL ans = 1;
    while( kt <= n ) kt *= k, ans++;
    cout << ans;
}