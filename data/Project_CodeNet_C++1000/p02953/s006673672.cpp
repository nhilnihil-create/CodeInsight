#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;


int main() {
  int n; cin >> n;
  vector<int> h(n);
  cin >> h[0];
  bool ok = true;
  for(int i = 1; i < n; ++i) {
    cin >> h[i];
    if(h[i]==h[i-1]) continue;
    h[i]--;
    if(h[i]<h[i-1]){
      ok = false;
      break;
    }
  }
  if(ok) cout <<"Yes" << endl;
  else cout << "No" << endl;
  return 0;
}