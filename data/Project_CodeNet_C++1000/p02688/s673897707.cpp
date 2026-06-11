#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for(int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;



int main() {
  int n, k;
  cin >> n >> k;
  vec<bool> having(n, false);
  rep(i, k){
    int d;
    cin >> d;
    rep(j, d){
      int a;
      cin >> a;
      having[a-1] = true;
    }
  }
  int ans = 0;
  rep(i, n){
    if(!having[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}