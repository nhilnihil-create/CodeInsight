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
      ll n, k;
      cin >> n >>k;
      int arr[n + 1];
      for(int i=1; i<n + 1; i++){
            cin >> arr[i];
      } 
      int visited[n + 1], index = 1, t;
      fill(visited, 0);
      vector<int> ans;
      ans.pb(1);
      visited[1] = 1;
      while(true){
            if(!visited[arr[index]]){
                  ans.pb(arr[index]);
                  visited[arr[index]] = 1;
                  index = arr[index];
            }
            else{
                  t = arr[index];
                  break;
            }
      }
      for(int i=0; i<ans.size(); i++){
            if(ans[i] == t){
                  t = i;
                  break;
            }
      }
      if(k <= t){
            cout << ans[k];
      }
      else{
            while(t--){
                  k--;
                  ans.erase(ans.begin());
            }
            cout << ans[(k) % ans.size()];
      }
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