#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int64_t> stairs(N + 1);
  stairs.at(0) = 1;
  int64_t MOD = 1000000000 + 7;
  set<int> broken;
  for(int i = 0; i < M; i++) {
    int a;
    cin >> a;
    broken.insert(a);
  }
  for(int i = 1; i <= N; i++) {
    if(i == 1) {
      if(broken.count(1)) {
        stairs.at(1) = 0;
      }
      else {
        stairs.at(1) = 1;
      }
    }
    else {
      if(broken.count(i)) {
        stairs.at(i) = 0;
      }
      else {
        stairs.at(i) = stairs.at(i - 1) + stairs.at(i - 2);
        stairs.at(i) %= MOD;
      }
    }
  }
  cout << stairs.at(N) << endl;  
}
