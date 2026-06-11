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
    vector<int> a;
    map<int, _LL> c;
    rep(i, n) 
    {
        int t;
        cin >> t;
        t--;
        a.push_back(t);
        c[t]++;
    }
    _LL total = 0;
    rep(i, n)
    {
        if( c[i] > 1 )
        {
            total +=  c[i] *  (c[i] - 1) / 2;
        }
    }
    
    rep(k, n)
    {

        _LL diff = 0;
        _LL ct = c[a[k]];
        if( ct > 1 )
        {
            diff = (ct - 1) * (ct - 2) / 2 - ct * (ct - 1) / 2;
        } 
        cout << total + diff << endl;
    }

    return 0;    
}