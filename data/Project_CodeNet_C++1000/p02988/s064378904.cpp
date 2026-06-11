#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int n;
  cin >> n;
  vector <int> p(n);
  rep(i,n) cin >> p[i];

  int ans = 0;
  for (int i = 1; i <= n - 2; i++){
    if (p[i] != max({p[i - 1], p[i], p[i + 1]}) && p[i] != min({p[i - 1], p[i], p[i + 1]})){
      ans ++;
    }
  }
  cout << ans << endl;
}
