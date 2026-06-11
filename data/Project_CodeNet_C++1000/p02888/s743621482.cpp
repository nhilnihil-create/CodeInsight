#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
    int n;
    cin >> n;
    vector<int> l;
    rep(i, n)
    {
        int t; cin >> t; l.push_back(t);
    }

    _LL ans = 0;
    sort(l.begin(), l.end());
    for(int a = 0; a < n; a++)
        for(int b = a + 1; b < n; b++)
        {
            int lb = l[b] - l[a];
            int ub = l[a] + l[b];
            int lbindex = upper_bound(l.begin(), l.end(), lb) - l.begin();
            int ubindex = lower_bound(l.begin(), l.end(), ub) - l.begin();
            if( b + 1 < ubindex )
            {
                ans += ubindex - max(lbindex, b + 1);
            }
        }

    cout << ans;
}