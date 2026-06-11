#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void)
{
    ll n;
    cin >> n;
    vector<pair<ll,ll>> f;
    for(ll i=2;i*i<=n;i++)
    {
        ll count=0;
        while(n%i==0)
        {
            n/=i;
            count++;
//            cout << n << endl;
        }
        f.emplace_back(i,count);
    }
    if(n!=1)
    {
        f.emplace_back(n,1);
    }
    int ans=0;
    for(auto p: f)
    {
        int i=1;
        while(p.second-i>=0)
        {
            p.second-=i;
            i++;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
