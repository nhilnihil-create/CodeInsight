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
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<vi> to(n);
  vi cnt(n),a(n-1),b(n-1);
  rep(i,n-1){
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
    to[a[i]].push_back(b[i]);
    to[b[i]].push_back(a[i]);
    cnt[a[i]]++;
    cnt[b[i]]++;
  }
  int ans = 0;
  rep(i,n) chmax(ans,(int)to[i].size());
  cout << ans;
  queue<int> q;
  vi node(n,-1);
  q.push(0);
  node[0] = 0;
  while(!q.empty()){
    int now = q.front(); q.pop();
    int cnt = node[now]+1;
    for(int next : to[now]){
      if(0 <= node[next]) continue;
      cnt %= ans;
      node[next] = cnt++;
      q.push(next);
    }
  }
  cout << "\n";
  rep(i,n-1){
    if(b[i] != 0) cout << node[b[i]]+1 << endl;
    else cout << node[a[i]]+1 << endl;
  }
  return 0;
}
