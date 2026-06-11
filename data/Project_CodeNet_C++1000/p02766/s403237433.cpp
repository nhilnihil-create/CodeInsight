#include<bits/stdc++.h>
using namespace std;
int main () {
  long long N, K;
  cin >> N >> K;
  int ans = 0;
  long long ret = 1;
  while (ret <= N) {
    ans ++;
    ret *= K;
  }
  cout << ans << endl;
}
