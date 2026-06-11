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
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> b = a;
  sort(b.rbegin(),b.rend());
  rep(i,n){
    int ans = b[0];
    if(b[0]==a[i]) ans = b[1];
    cout << ans << endl;
    }
  return 0;
}