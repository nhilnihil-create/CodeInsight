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
    int n,i,j,ans=0;
    cin>>n;
    vector<int>a(n+1),b(n+1),c(n);
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(i=1;i<n;i++)
    {
        cin>>c[i];
    }
    int prv=-1;
    for(i=1;i<=n;i++)
    {
        j=a[i];
        ans+=b[j];
        if(prv+1==j)
        ans+=c[prv];
        prv=j;
    }
    cout<<ans<<endl;
    return 0;
}
