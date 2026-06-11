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
  int n; cin >> n;
  vi a(n);
  vector<vi> x(n),y(n);
  rep(i,n){
    cin >> a[i];
    x[i].resize(a[i]);
    y[i].resize(a[i]);
    rep(j,a[i]){
      cin >> x[i][j] >> y[i][j];
      x[i][j]--;
    }
  }
  int ans = 0;
  rep(bit,1<<n){
    bool ok = true;
    rep(i,n){
      if(bit>>i & 1){
        rep(j,a[i]){
          if((bit>>x[i][j] & 1)^y[i][j]) ok = false;
        }
      }
    }
    if(ok) chmax(ans,__builtin_popcount(bit));
  }
  cout << ans;
  cout << "\n";
  return 0;
}
