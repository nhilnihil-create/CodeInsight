#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n-1);
  REP(i,n-1) cin >> b[i];

  a[0] = b[0];
  a[n-1] = b[n-2];

  for(int i = 1; i < n-1; i++){
    a[i] = min(b[i], b[i-1]);
  }

  int ans = 0;
  REP(i,n) ans += a[i];

  //for(auto x: a) cout << x << endl;

  cout << ans << endl;
  return 0;
}