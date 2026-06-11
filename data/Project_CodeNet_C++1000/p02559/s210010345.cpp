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
    fenwick_tree<_LL> ft(n);
    rep(i, n) { _LL a; cin >> a; ft.add(i, a); }
    rep(i, q)
    {
        _LL t, q1, q2;
        cin >> t >> q1 >> q2;
        switch(t)
        {
            case 0:
                ft.add(q1, q2);
                break;
            case 1:
                cout << ft.sum(q1, q2) << endl;
                break;
        }
    }
    return 0;    
}