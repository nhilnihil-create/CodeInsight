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

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  for(int i = 1; i < n; i++){
    if(a[i-1] < a[i]) a[i]--;
  }
  bool ok = true;
  for(int i = 1; i < n; i++){
    if(a[i-1] > a[i]) ok = false;
  }
  cout << (ok ? "Yes" : "No");
  cout << "\n";
  return 0;
}
