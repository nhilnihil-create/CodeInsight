#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define see(x) cout<<#x<<" : "<<(x)<<endl;
#define ya cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define ff first
#define sc second
typedef unsigned long long ll;
using namespace std;
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL),cout.tie(NULL);
    ll n,i,j,ans=0;
    cin>>n;
    vector<ll>a(n+2),b(n+1);
    for(i=1;i<=n+1;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    ll t=0;
    for(i=1;i<=n;i++)
    {
        ans+=min(b[i],a[i]);
        t=a[i];
        a[i]-=min(b[i],t);
        b[i]-=min(b[i],t);
        ans+=min(b[i],a[i+1]);
        t=a[i+1];
        a[i+1]-=min(b[i],t);
        b[i]-=min(b[i],t);
    }
    cout<<ans<<endl;
    return 0;
}
