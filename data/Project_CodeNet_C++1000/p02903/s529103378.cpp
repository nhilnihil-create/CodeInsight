#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()

#define READ(x) (cin >> (x))
#define WRITE_N(x) (cout << (x) << endl)
#define WRITE(x) (cout << (x))
#define WRITE_YESNO(x) (WRITE_N(x ? "Yes" : "No"))

int main() {
  // get values from input
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W, A, B;
  cin >> H >> W >> A >> B;
  
  // main procedure
  // output
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      cout << (((i < B && j < A) || (i >= B && j >= A)) ? 0 : 1);
    }
    cout << endl;
  }

  return 0;
}
