#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  vector<int> vec2(N);
  int sum = 0;
  rep(i, N) {
    cin >> vec.at(i);
    sum += vec.at(i);
  }
  rep(i, N) {
    if(i == 0) {
      vec2.at(i) = sum - vec.at(i);
    }
    else {
      vec2.at(i) = vec2.at(i - 1) - vec.at(i);
    }
  }
  int MI = 10000;
  rep(i, N) {
    MI = min(abs(vec2.at(i) - (sum - vec2.at(i))), MI);
  }
  cout << MI << endl;
}