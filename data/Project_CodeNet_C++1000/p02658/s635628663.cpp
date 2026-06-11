#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};


int main() {
  int n;
  cin >> n;
  vec<ll> a(n);
  rep(i, n){
    cin >> a[i];
    if(a[i] == 0){
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = 1;
  rep(i, n){
    if(a[i] <= 1000000000000000000 / ans){
      ans *= a[i];
    }
    else{
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}