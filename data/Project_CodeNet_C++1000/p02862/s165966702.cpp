#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define vlli vector<ll>
#define vi vector<int>
#define vs vector<string>
#define vplli vector< pair< ll,ll> >
#define plli pair< ll,ll >
#define vps vector< pair< string, string> >
#define vpi vector< pair< int, int> >
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define forn(i,a,n) for(ll i=a;i<n;i++)
#define scan(arr,a,n) for(ll i=(a);i<(n);i++)cin>>(arr)[i];
#define print(arr,a,n) for(ll i=(a);i<(n);i++)cout<<(arr)[i]<<" ";

ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}

ll x, y;
ll C(ll n, ll r) { 
    
    
    if (r == 0 || r == n) {
        return 1; 
    }
    ll fn = 1, fr, fnr;
    for (ll i = 1; i <= n; i++) {
        fn = mul(fn, i);
        if(i==r){
            fr = fn;
        }
        if(i==n-r){
            fnr = fn;
        }
    }
    // cout<<fn<<" "<<fnr<<" "<<fr<<endl;
  
    return mul(mul(fn, mod_inv(fr)), mod_inv(fnr)); 
} 
int main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif

    cin>>x>>y;
    if((x+y)%3 != 0){
        cout<<0<<endl;
        return 0;
    }
    ll n, m;
    m = (2*x - y)/3;
    n = (2*y - x)/3;
    if(m<0 || n<0){
        cout<<0<<endl;
        return 0;
    }
    if(m==0 || n==0){
        cout<<1<<endl;
        return 0;
    }
    cout<<C(n+m, m)<<endl;
    
}