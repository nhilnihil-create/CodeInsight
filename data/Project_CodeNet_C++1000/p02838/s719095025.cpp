#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> data(60, 0);
  for(int i = 0; i < N; i++) {
    int64_t a;
    cin >> a;
    bitset<60> s(a);
    for(int j = 0; j < 60; j++) {
      if(s.test(j)) {
        data.at(j)++;
      }
    }
  }
  int64_t ans = 0;
  for(int i = 0; i < 60; i++) {
    int64_t a = data.at(i) * (N - data.at(i)) % 1000000007;
    int64_t b = 1;
    for(int j = 0; j < i; j++) {
      b *= 2;
      b %= 1000000007;
    }
    ans += a * b % 1000000007;
  }
  cout << ans % 1000000007 << endl;
}