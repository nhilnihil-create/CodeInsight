#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, x;
    cin >> n >> m >> x;

    vector<ll> prices(n);
    vector<vector<ll>> points(n, vector<ll> (m));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= m; ++j)
        {
            if(j == 0)
                cin >> prices[i];
            else 
            {
                cin >> points[i][j-1];
            } 
        }
    }

    ll res = INT_MAX;
    for(int bit = 0; bit < 1 << n; ++bit)
    {
        ll p = 0;
        vector<ll> sum(m, 0);
        for(int i = 0; i < n; ++i)
        {
            if(bit & (1<<i))
            {
                p += prices[i];
                for(int j = 0; j < m; ++j)
                {
                    sum[j] += points[i][j];
                }
            }
        }

        bool check = true;
        for(auto j: sum)
            if(j < x)
                check = false;

        if(check)
            res = min(res, p);
    }

    cout << (res == INT_MAX ? -1 : res) << "\n";
    return 0;
}