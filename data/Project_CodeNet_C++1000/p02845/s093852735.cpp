#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<long> data(N + 1);
  data.at(0) = 3;
  long ans = 1, a;
  for(int i = 0; i < N; i++){
    cin >> a;
    ans *= data.at(a);
    data.at(a)--;
    data.at(a + 1)++;
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}