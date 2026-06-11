#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define LOL cout << '\n';
#define sz(x) ((int)x.size())
#define INF LONG_LONG_MAX
#define NINF LONG_LONG_MIN
#define deb(x) cout << "[" << (#x) << "=" << x << "]" << '\n';
#define deb2(x,y) cout << "[" << (#x) << "=" << x << "] [" << (#y) << "=" << y << "]" << '\n';
#define deb3(x,y,z) cout << "[" << (#x) << "=" << x << "] [" << (#y) << "=" << y << "] [" << (#z) << "=" << z << "]" << '\n';

const int N=5e5+107;
vector<int> adj[N];
vector<int> h(N);

bool isvis(int yo){
  int itsheight=h[yo];
    //deb(itsheight);
  for(auto u:adj[yo]){
    if(h[u]>=itsheight){
      return 0;
    }
  }
  return 1;
}

void solve(){
  int n,m; cin>>n>>m;
  for(int i=1 ; i<=n ; i++){
    cin>>h[i];
  }
  for(int i=0,u,v ; i<m ; i++){
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  int cnt=0;
  for(int i=1 ; i<=n ; i++){
    if(isvis(i)){
      cnt++;
    }
 //     deb(cnt);
  }
  cout<<(cnt);LOL
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int _ = 1; //cin >> _;
  for(int i = 1 ; i <= _ ; i++){
    //cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}