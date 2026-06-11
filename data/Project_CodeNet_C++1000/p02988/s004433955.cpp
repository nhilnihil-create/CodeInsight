#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  vector<int> vec2(N-1);
  rep(i, N) {
    if(i == 0) {
      cin >> vec.at(i);
    }
    else {
      cin >> vec.at(i);
      if(vec.at(i-1) < vec.at(i)) {
        vec2.at(i-1) = 1;
      }
      else {
        vec2.at(i-1) = -1;
      }
    }
  }
  int ans = 0;
  rep(i, N-2) {
    if(vec2.at(i) + vec2.at(i+1) != 0) {
      ans++;
    }
  }
  cout << ans << endl;
}