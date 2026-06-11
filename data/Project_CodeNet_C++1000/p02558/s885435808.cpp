#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <atcoder/all>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)
using namespace atcoder;

int main()
{
    int n, q; cin >> n >> q;
    dsu ds(n);
    rep(i, q)
    {
        int t, u, v;
        cin >> t >> u >> v;
        switch(t)
        {
            case 0:
                ds.merge(u, v);
                break;
            case 1:
                cout << (ds.same(u, v) ? 1 : 0) << endl;
                break;
        }
    }
    return 0;    
}