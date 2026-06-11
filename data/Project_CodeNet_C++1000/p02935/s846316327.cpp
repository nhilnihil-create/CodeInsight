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
    vector<double> v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    double ans = 0;
    rep(i, n)
    {
        if(i == 0)
        {
            ans = v[0];
        }
        else
        {
            ans = (ans + v[i]) / 2;
        }
    }
    cout << std::fixed << std::setprecision(15) << ans << endl;
    return 0;    
}