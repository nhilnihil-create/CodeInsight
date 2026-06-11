#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
inline void normal(ll &a)
{
    a %= MOD;
    (a < 0) && (a += MOD);
}
inline ll modMul(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a*b)%MOD;
}
inline ll modAdd(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a+b)%MOD;
}
main()
{
    int t=1;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        ll ans=0;
        for(int i=k; i<=n+1; i++)
        {

            ans=modAdd((modAdd((modMul((n-i+1),i)),1)),ans);


        }
        cout<<ans<<endl;
    }

}
