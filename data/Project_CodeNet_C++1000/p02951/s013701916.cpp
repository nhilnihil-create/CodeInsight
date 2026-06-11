#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
//using T = tuple<string, int, int>;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  cout << max(C-(A-B), 0) << endl;

  return 0;
}

// https://github.com/atcoder/live_library