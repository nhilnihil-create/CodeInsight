#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,m; cin >> n >> m;
  vi h(n); rep(i,n) cin >> h[i];
  vector<vi> to(n);
  rep(i,m){
    int a,b; cin >> a >> b;
    --a; --b;
    to[a].emplace_back(b);
    to[b].emplace_back(a);
  }
  int ans = 0;
  rep(i,n){
    int mx = h[i];
    bool ok = true;
    for(int tmp : to[i]){
      if(mx <= h[tmp]) ok = false;
    }
    if(ok) ans++;
  }
  cout << ans;
  cout << endl;
  return 0;
}
