#include<bits/stdc++.h>
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define s second
#define int long long
#define sz(x) (ll)(x.size())
using namespace std;


const int mod = 1e9+7;

int expo_pow(int x,int y){
 if(y == 0) return 1;
  y=y%(mod-1);
  x%=mod;
  if(y==0) y=mod-1;
  int res=1;
  while(y){
    if(y&1) res=(res*x)%mod;
    x=(x*x)%mod;
    y>>=1; 
  }
  return res;
}

ll add()
{
    return 0;
}

template <typename T, typename... Types>
T add(T var1, Types... var2){
    return (((((ll)(var1)) % mod + (ll)(add(var2...))) % mod) + mod) % mod;
}

ll mul(){
    return 1;
}

template <typename T, typename... Types>
T mul(T var1, Types... var2){
    return (((ll)(var1)) % mod * (ll)(mul(var2...))) % mod;
}
const int inf = 9223372036854775807;
vector<int> val,perm;
int n,k;

int get(vector<int>& a) {
  int n = a.size();
  
  int total =  0;
  for (int i = 0; i < n; ++i) total += a[i];

  int ans = -inf;
  for(int i = 0;i < n; ++i) {
    int tot = 0;
    for(int j = 0;j < n; ++j) {
      tot += a[(i + j)%n];
      if(j+1 > k) break;
      int muli = (k - j -1)/n;
      ans = max(tot + max(total*muli,0LL),ans);
    }
  }
  return ans;
}

void solve(){
  cin >> n >> k;
  val.resize(n+1);
  perm.resize(n+1);
  int visited[n+1] = {0};

  for (int i = 1; i <= n; ++i) {
    cin >> perm[i];
  }
  
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  
  int ans = -inf;
  for (int i = 1; i <= n; ++i) {
    if (visited[i] != 1) {
      vector<int> tmp;
      int cur = perm[i];
      while(cur!=i) {
        visited[cur] = 1;
        tmp.pb(val[cur]);
        cur = perm[cur];
      }
      visited[i] = 1;
      tmp.pb(val[i]);
      ans = max(ans,get(tmp));
    }
  }
  cout << ans << "\n";
}


signed main(){
//  fast;
  int test = 1;
  int i=1;
  while(test--){
    solve();
  }
}



