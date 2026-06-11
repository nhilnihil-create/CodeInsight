#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<int> B(N - 1);
  for(int i = 0; i < N - 1; i++) {
    cin >> B.at(i);
  }
  long long ans = B.at(0);
  for(int i = 1; i < N - 1; i++) {
    ans += min(B.at(i - 1), B.at(i));
  }
  ans += B.at(N - 2);
  cout << ans << endl;
}