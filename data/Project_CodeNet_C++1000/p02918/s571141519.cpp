#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int diff = 0;
    rep(i, n - 1)
    {
        if( s[i] != s[i + 1] ) diff++;
    }
    int ldiff = max(0, diff - 2 * k);
    cout << n - 1 - ldiff << endl;
    return 0;    
}