#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, k, n) for (int i = k; i < (int)(n); i++)
#define coyes cout << "Yes" << endl;
#define cono cout << "No" << endl;
#define coYes cout << "YES" << endl;
#define coNo cout << "NO" << endl;
using namespace std;
using ll = long long int;
string large_al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string small_al = "abcdefghijklmnopqrstuvwxyz";
using Graph = vector<vector<int>>;
using i64 = int64_t;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  if (h > w) {
    if (n % h == 0) {
      cout << n / h << endl;
    }
    else {
      cout << n / h + 1 << endl;
    }
  }
  else {
    if (n % w == 0) {
      cout << n / w << endl;
    }
    else {
      cout << n / w + 1 << endl;
    }
  }
}

