//   Rishabh Agarwal
#include <bits/stdc++.h>
#define F first
#define S second
#define MAX 10000003
using namespace std;

typedef long long int ll;
const ll mod = 1e17;
long double PI=3.1415926;

ll power(ll a,ll b){
    if(b==0){
        return 1;
    }
    ll temp=power(a,b/2)%mod;
    if(b%2==0){
        return (temp*temp)%mod;
    }
    else{
        return ((a*temp)%mod*temp)%mod;
    }
}

ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

//vector<ll>v;
//vector<ll>::iterator it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    //cin>>t;
    t=1;
    //ll c=1;
    while(t--){
        ll n;
        cin>>n;
        ll a[n+1];
        for(ll x=0; x<=n; x++){
            cin>>a[x];
        }
        ll b[n+1];
        b[n]=a[n];
        for(ll x=n-1; x>=0; x--){
            b[x]=a[x]+b[x+1];
        }
        ll ans=0;
        ll c[n+1];
        //if(a[0]!=0){ans=-1;}
      //else{
       c[0]=1;
        ans+=c[0];
        for(ll x=1; x<=n; x++){
          c[x]=min(b[x],2*(c[x-1]-a[x-1]));
          ans+=c[x];
        }
      //}
      for(ll x=0; x<n+1; x++){
       if(c[x]<a[x]){
         ans=-1;
         break;
       }
      }
        cout<<ans<<"\n";
        //v.clear();
        //cout<<"Case #"<<c<<": "<<ans<<"\n";
        //c++;
    }
    return 0;
}
