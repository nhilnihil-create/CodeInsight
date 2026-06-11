#include <bits/stdc++.h>
#include <stdio.h>
#define ll long long
#define fr(i,p,n) for(ll i=p;i<n;i++)
#define fr1(i,p,n) for(ll i=p;i>=n;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define precise cout << std::setprecision(10) << std::fixed;
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+1];
        fr(i,0,n+1) cin>>a[i];
        if(n==0)
        {
             if(a[0]==1) cout<<1<<endl;
             else cout<<-1<<endl;
             continue;
        }
        ll mn[n+1],mx[n+1];
        mx[0]=1,mn[0]=a[0]+1;
        mx[n]=a[n],mn[n]=a[n];
        fr(i,1,n)
        {
            if((mx[i-1]-a[i-1])<pow(2,62)) mx[i]=(mx[i-1]-a[i-1])*2;
            else mx[i]=LLONG_MAX;
            mn[i]=a[i]+1;
        }
        fr1(i,n-1,1)
        {
            mx[i]=min(mx[i],mx[i+1]+a[i]);
            mn[i]=max(mn[i],(ll)(ceil(mn[i+1]/2.0))+a[i]);
        }
        ll ans=0;
        bool f=0;
        fr(i,0,n+1)
        {
            ans+=mx[i];
            if(mn[i]>mx[i])
            {
                f=1;
                break;
            }
        }
        if(f==1) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
