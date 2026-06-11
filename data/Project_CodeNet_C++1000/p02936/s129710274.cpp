#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
vector<vi> to;
vi ans;
void dfs(int now, int parent = -1){
  for(int next : to[now]){
    if(next == parent) continue;
    ans[next] += ans[now];
    dfs(next,now);
  }
}
int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,q; cin >> n >> q;
  to = vector<vi>(n);
  rep(i,n-1){
    int a,b; cin >> a >> b;  a--;  b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  ans = vi(n);
  rep(i,q){
    int p,x; cin >> p >> x;  p--;
    ans[p] += x;
  }
  dfs(0);
  rep(i,n) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
