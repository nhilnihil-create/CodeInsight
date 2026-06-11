#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, K, d, a, ans = 0;
  cin >> N >> K;
  vector<int> people(N);
  
  for (int i = 0; i < K; i++) {
    cin >> d;
    for (int j = 0; j < d; j++) {
      cin >> a;
      people.at(a-1) += 1;
    }
  }
  
  for (int x = 0; x < N; x++) {
    if (people.at(x) == 0) ans += 1;
  }
  
  cout << ans << endl;
}