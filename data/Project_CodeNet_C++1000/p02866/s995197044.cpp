//   Rishabh Agarwal
#include <bits/stdc++.h>
#define F first
#define S second
#define MAX 10000003
using namespace std;

typedef long long int ll;
const ll mod = 998244353;
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
        ll a[n];
        ll v[n];
        memset(v,0,sizeof(v));
        ll ans=1;
        for(ll x=0; x<n; x++){
            cin>>a[x];
            v[a[x]]++;
        }
        if(v[0]!=1){
            ans=0;
        }
        else if(v[0]==1&&a[0]!=0){
            ans=0;
        }
        else{
            ll k=n;
            for(ll x=n-1; x>=0; x--){
                if(v[x]==0){
                    k--;
                }
                else{
                    break;
                }
            }
            for(ll x=1; x<k; x++){
                ans=ans%mod;
                ans*=power(v[x-1],v[x])%mod;
                ans=ans%mod;
            }
        }
        cout<<ans<<"\n";
        //v.clear();
        //cout<<"Case #"<<c<<": "<<ans<<"\n";
        //c++;
    }
    return 0;
}