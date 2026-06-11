#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long int
#define mod 100000007
#define start int t;cin>>t;while(t--)
#define debug(x) cout<<"#"<<x<<"\n"
#define en "\n"
#define vi vector<int>
#define vli vector<long long int>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define print_all(x) for(auto t:x) cout<<t<<" "; cout<<en
#define F first
#define S second
#define ss(s) scanf("%s",&s)
#define si(x) scanf("%d",&x)
#define sli(x) scanf("%lld",&x)
#define ss(s) scanf("%s",&s)
using namespace std;
ll mod_pow(ll x, int n){
    if(n == 0)      return 1;
 
    ll res = 1;
    while(n > 0){
        if(n & 1)   res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
 
    return res;
}
vector<ll> allDivisors(ll n) 
{ 
    vector<ll> v;
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                v.pb(i);
  
            else {
                v.pb(i);
                v.pb(n/i);
            } 
        }
    }
    return v;
} 
//int hash[1001];
void solve(){
        ll a,b;
  		cin>>a>>b;
  		unsigned ll xx=(a*b);
        if(a==1 || b==1){
            cout<<"1"<<en;
        }
        else cout<<(xx+1)/2<<en;
}

int main(){
    fast;
    //start{
        solve();
    //}
    return 0;
}

