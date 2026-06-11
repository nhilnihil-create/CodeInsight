#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define loop(a,b)            for(ll i=a;i<=b;i++)
#define sci(n)               scanf("%d",&n)
#define scl(n)               scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define srt(g)               sort(g.begin(),g.end())
#define rvs(g)               reverse(g.begin(),g.end())
#define pl                   pair<long long,long long>
#define ll long long
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define f first
#define s second
int main()
{
    int n;
    scl(n);
    int a[n+5];
    map<int,int>mp;
    ll ans=0;
    FOR(i,n)
    {
        scl(a[i]);
        mp[i+a[i]]++;
    }
    FOR(i,n)
    {
        ll k=i-a[i];
        if(1<=k && k<n && mp[k]>0)
        {
            ans=ans+mp[k];
        }
    }
    cout << ans << "\n";
}

