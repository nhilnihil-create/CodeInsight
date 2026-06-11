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
    double ret = 0;
    rep(i, n)
    {
        double a; cin >> a;
        ret += 1.0 / a;
    }
    cout << std::fixed << std::setprecision(15) << 1.0 / ret;
    return 0;    
}