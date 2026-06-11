#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long , long long>
#define pb push_back
#define ll long long
#define ld long double
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define fill(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
ll power(ll x,ll y,ll m){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%m;x=x*x%m;}return r;}
const ll mod = 1e9 + 7;
const ld pi = 3.14159265358979;
    
ll solve(ll n, ll a){
      if(n-a < a){
            a = n-a;
      }
      ll x = 1, y = 1;
      for(ll i = 1; i<=a; i++){
            x = (x * i)  % mod;
            y = (y * (n - i + 1)) % mod;
      }
      return (y*power(x, mod-2, mod))%mod;
}

int run_test(){
      ll n,a ,b;
      cin >> n >> a >> b; 
      ll t  = power(2, n, mod);
      t = (t - 1 + mod)%mod;
      t = (t - solve(n ,a) + mod) % mod;
      t = (t - solve(n, b) + mod) % mod;
      cout << t;
      return 0; 
}
    
int main(){
   FAST;
    ll t;
    t = 1;
     
    while(t--){
        run_test();
    }
}