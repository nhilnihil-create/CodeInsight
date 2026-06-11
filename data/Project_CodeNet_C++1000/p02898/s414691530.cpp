#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, K;
  cin >> N >> K;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    if (A >= K) {
      ans++;
    }
  }
  cout << ans << endl;
}