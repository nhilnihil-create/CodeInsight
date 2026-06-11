#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int x,y,a,b,c; cin >> x >> y >> a >> b >> c;
  vi p(a),q(b),r(c);
  rep(i,a) cin >> p[i];
  rep(i,b) cin >> q[i];
  rep(i,c) cin >> r[i];
  sort(all(p),greater<int>());
  sort(all(q),greater<int>());
  // sort(all(r),greater<int>());
  priority_queue<int,vi,greater<int>> res;
  rep(i,x) res.push(p[i]);
  rep(i,y) res.push(q[i]);
  rep(i,c){
    if(res.top() < r[i]){
      res.pop();
      res.push(r[i]);
    }
  }
  ll ans = 0;
  while(!res.empty()){
    ans += res.top();
    res.pop();
  }
  cout << ans;
  cout << "\n";
  return 0;
}
