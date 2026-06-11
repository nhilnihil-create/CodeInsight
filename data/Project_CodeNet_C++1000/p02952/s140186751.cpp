#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
//using T = tuple<string, int, int>;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (to_string(i).size() % 2 == 1) {
      ans++; 
    }
  }

  cout << ans << endl;
  
  return 0;
}

// https://github.com/atcoder/live_library