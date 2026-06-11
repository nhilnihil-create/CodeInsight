#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H,W,A,B; cin >> H >> W >> A >> B;
  rep(h, H) {
    rep(w, W) {
      if((h < B && w < A) || (h >= B && w >= A)) {
        cout << 0;
      } else {
        cout << 1;
      }
    }
    cout << endl;
  }
}
