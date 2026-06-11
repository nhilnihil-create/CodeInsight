#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N;
  cin >> N;
  vector<int> vec(N);
  ll sum = 0;
  rep(i, N) {
    cin >> vec.at(i);
    sum += vec.at(i);
  }
  ll ans = 0;
  rep(i, N) {
    ans += vec.at(i) * (sum - vec.at(i));
  }
  cout << ans / 2 << endl;
}