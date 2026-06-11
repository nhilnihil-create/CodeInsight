#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int n, k;
  cin >> n >> k;
  vector <int> p(n);
  rep(i,n) cin >> p.at(i);

  sort(all(p));

  int ans = 0;
  rep(i,k) ans += p.at(i);
  cout << ans << endl;
}
