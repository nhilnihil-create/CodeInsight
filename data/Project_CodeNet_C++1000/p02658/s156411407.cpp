#include <bits/stdc++.h>
using namespace std;

int keta(int64_t x) {
  int ans=0;
  while (x>0) {
    x /= 10;
    ans++;
  }
  return ans;
}

int main() {
  int64_t N;
  cin >> N;
  int64_t p;
  int64_t sum=1;
  int finish = 1;
  int64_t INF = pow(10, 18);
  vector<int64_t> V(N);
  
  for (int64_t i=0; i<N; i++) {
    cin >> V.at(i);
    if (V.at(i) == 0) {
      finish = 0;
    }
  }
  
  
  if (finish != 0) {
    for (int64_t i=0; i<N; i++) {
      if (keta(sum) + keta(V.at(i)) > 19 && sum*V.at(i) != INF) {
        finish = -1;
        break;
      }
      sum *= V.at(i);
      if (sum > INF || sum < 0) {
        finish = -1;
        break;
      }
    }
  }
  
  if (finish == 0) {
    cout << 0 << endl;
  }
  else if (finish == -1) {
    cout << -1 << endl;
  }
  else {
    cout << sum << endl;
  }
  //cout << sum << endl;
}