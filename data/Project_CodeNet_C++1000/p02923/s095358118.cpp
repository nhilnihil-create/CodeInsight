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
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    int total = 0;
    int current = 0;
    rep(i, n - 1)
    {
        if( h[i + 1] <= h[i] )
        {
            current++;
            total = max(total, current);
        }
        else
        {
            current = 0;
        }
    }
    cout << total << endl;
    return 0;    
}