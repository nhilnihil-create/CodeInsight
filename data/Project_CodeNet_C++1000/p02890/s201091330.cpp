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
    int *ac = new int[n];
    rep(i, n) ac[i] = 0;
    rep(i, n)
    {
        int a;
        cin >> a;
        ac[a - 1]++;
    }

    int *nt = new int[n + 1];
    rep(i, n + 1) nt[i] = 0;
    rep(i, n)
    {
        nt[ac[i]]++;
    }

    vector<pair<int,int>> list;
    int totalcount = 0;
    int pre = n;

    int *left = new int[n];

    for( int i = n; i > 0; i--)
    {
        totalcount += nt[i];
        left[i - 1] = pre - totalcount;
        pre = left[i - 1];
    }

    // k == 1
    cout << n << endl;
    for( int k = 2; k <= n; k++ )
    {
        int r = n / k;
        int l = 0;
        if( left[r] >= r * k )
        {
            cout << r << endl;
            continue;
        }

        while( l + 1 < r )
        {
            int m = (r + l) / 2;
            if( left[m] >= m * k )
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }

        cout << l << endl;
    }

    delete nt;
    delete ac;
}