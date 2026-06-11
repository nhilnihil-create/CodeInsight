#pragma GCC target ("avx2")
#pragma GCC optimize "trapv"
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define input(a,n) for(ll i1=0;i1<n;i1++)cin>>a[i1]
#define ll long long
#define pi 2 * acos(0.0)
#define usll unordered_set<ll>
#define sll set<ll>
#define vll vector<ll>
#define mll map<ll,ll>
#define pll pair<ll,ll>
#define umll unordered_map<ll,ll>
#define S second
#define sz size()
#define all(v) v.begin(),v.end()
#define Y cout<< "YES"<< "\n"
#define N cout<< "NO"<< "\n"
#define F first
#define mp make_pair
#define pb push_back
#define pf push_front
#define ld long double
#define mod 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,k,c,ans=0,f=0;
    cin>>n>>m>>k;
    vll a,b;
    for(ll i=0;i<n;i++)
    {
        cin>>c;
        a.pb(c);
    }
    for(ll i=0;i<m;i++)
    {
        cin>>c;
        b.pb(c);
    }
    for(ll i=1;i<n;i++)
    {
        a[i]=a[i-1]+a[i];
    }
    for(ll i=1;i<m;i++)
    {
        b[i]=b[i-1]+b[i];
    }
    for(ll i=0;i<m;i++)
    {
        if(b[i]<=k)
        {
            f=1;
            ans=i+1;
        }
        else
        {
            break;
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(a[i]>k)
            break;
        if(upper_bound(all(b),k-a[i])!=b.end())
        {
            ll p=upper_bound(all(b),k-a[i])-b.begin();
            ans=max(ans,i+p+1);
            //cout<<i+p+1<< "\n";
        }
        else
        {
            ans=max(ans,i+m+1);
        }
    }
    cout<<ans;
    return 0;
}
