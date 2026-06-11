#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _LL long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    int *x = new int[n];
    rep(i, n) cin >> x[i];

    int bestp = 1;
    int bestpow = (1 << 30);

    rep(p, 100)
    {
        int tp = 0;
        rep(i, n) tp += (x[i] - p) * (x[i] - p);
        if( tp < bestpow )
        {
            bestpow = tp;
            bestp = p;
        }
    }

    cout << bestpow << endl;
}