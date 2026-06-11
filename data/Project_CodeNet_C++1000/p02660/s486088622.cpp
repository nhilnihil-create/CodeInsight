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
      ll n;
      cin >> n;
      int k = floor(sqrt(n));
      int visited[k];
      fill(visited, 0);
      int ans = 0;
      for(int i=2; i<=k; i++){
            if(visited[i]) continue;
            int count = 0;
            while(n % i == 0){
                  count++;
                  n /= i;
            }
            for(int j = i; j<=k; j+=i){
                  visited[j] = 1; 
            }
            ans += ((sqrt(1 + 8*count) - 1)/2);
      }
      if(n != 1){
            ans++;
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