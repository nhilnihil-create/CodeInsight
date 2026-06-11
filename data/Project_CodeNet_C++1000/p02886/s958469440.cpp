#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  vector<int> d(N);
  for (int i = 0; i < N; i++) {
    cin >> d.at(i);
  }
  int ans = 0;
  int memo = 1;
  for (int i = 0; i < N - 1; i++) {
    for (int j = memo; j < N; j++) {
      ans += (d.at(i) * d.at(j));
    }
    memo++;
  }
  cout << ans << endl;
}