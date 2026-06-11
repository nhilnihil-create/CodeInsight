#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<ll>>;

int main(void)
{
    ll n,m;
    cin >> n >> m;
    ll a,b;
    vector<ll> h(n),ma(n,0);

    for(int i=0;i<n;i++)
    {
        cin >> h[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        a--;
        b--;
        ma[a]=max(ma[a],h[b]);
        ma[b]=max(ma[b],h[a]);
    }
    
    ll count=0;
    for(int i=0;i<n;i++)
    {
        if(h[i]>ma[i])
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
