#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

int main(void)
{
    int n,m;
    ll x;
    cin >> n >> m >> x;
    ll c[n];
    ll a[n][m];
    ll min_money=LLONG_MAX;
    for (int i=0;i<n;i++)
    {
        cin >> c[i];
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }

    for(int bit=0;bit<pow(2,n);bit++)
    {
        //cout << "bit " << bit << endl;
        ll money=0;
        ll b[m]={};
        int ok=0;
        for(ll i=0;i<n;i++)
        {
            if(bit & (1<<i))
            {
                money+=c[i];
                for(ll j=0;j<m;j++)
                {
                    b[j]+=a[i][j];
                }
            }
        }
        for(ll j=0;j<m;j++)
        {
            if(b[j]>=x)
            {
                ok++;
                //cout << b[j] << endl;
            }
        }
        if(ok==m)
        {
            if(money<min_money)
            {
                min_money=money;
            }
        }
    }
    if(min_money != LLONG_MAX)
    {
        cout << min_money << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
