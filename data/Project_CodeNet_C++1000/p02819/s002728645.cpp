#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<bool> prime(100010,true);
  prime[1] = false;
  for(int i = 2; i*i <= 100010; i++) {
    if (!prime[i]) continue;
    for(int j = i*2; j <= 100010; j += i) {
      prime[j] = false;
    }
  }
  int x;
  cin >> x;
  int ans = 0;
  while(ans == 0) {
    if (prime[x]) {
      ans = x;
    }
    x++;
  }
  cout << ans << endl;
  return 0;
}
