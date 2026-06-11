#include<bits/stdc++.h>
#include<cmath>
#define pb push_back
#define ld long double
#define mp make_pair
#define vl vector<ll> 
#define vd vector<double>
#define vld vector<long double>
#define ll long long int
#define pl pair<ll, ll>
#define all(a) a.begin(), a.end()
#define forr(i, n) for(ll i=0; i<n; i++) 
#define forr1(i, n) for(ll i=1; i<=n; i++)
using namespace std;
const ld PI =3.1415926535897923846;
const ll MOD = 1e9+7;
void solve()
{
    ll n, k;
    cin>>n>>k;
    n;
    vl sum(200015, 0);
    for(ll i=1; i<200015; i++)
    {
        sum[i]=i+sum[i-1];
        sum[i]%=MOD;
    }
    ll ans=0;
    for(ll j=k; j<=1+n; j++)
    {
        ll sum1=sum[n]-sum[n-j<0?0:n-j];
        ll sum2=sum[j-1];
        ans+=sum1-sum2+1;
        ans%=MOD;
        //cout<<sum1<<" "<<sum2<<endl;
    }
    if(ans<0)
    ans+=MOD;
    cout<<ans;
}
int main()
{
    ll test=1;
    //cin>>test;
    while(test--)
        solve();
}