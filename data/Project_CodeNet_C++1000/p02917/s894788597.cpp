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
    vector<ll>a(n+2),b(n);
    for(i=1;i<n;i++)
    {
        cin>>b[i];
    }
    ll prv=LONG_MAX;
    for(i=1;i<n;i++)
    {
        a[i]=min(b[i],prv);
        a[i+1]=b[i];
        prv=b[i];
    }
    for(i=1;i<=n;i++)
    {
        ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}