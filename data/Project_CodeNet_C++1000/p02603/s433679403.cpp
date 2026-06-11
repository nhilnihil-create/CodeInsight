#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,v[2001],ans,money,stocks;
pll dp[81][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    money=1000;
    for(int i=1;i<n;i++)
    {
        stocks=0;
        if(v[i]<v[i+1])
            stocks=money/v[i];
        money+=(v[i+1]-v[i])*stocks;
    }
    cout<<money;
    return 0;
}
