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
 
int run_test(){
      int n,m;
      cin >> n >> m;
      int h[n + 1];
      for(int i=1; i<=n; i++){
            cin >> h[i];
      }
      vector<int> v[n + 1];
      int ans =0; 
      for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            v[a].pb(b);
            v[b].pb(a);
      }
      for(int i=1; i<=n; i++){
            bool flag = false;
            for(auto x: v[i]){
                  if(h[i] <= h[x]){
                        flag= true;
                        break;
                  }
            }
            if(flag == false){
                  ans++;
            }
      }
      cout << ans;
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