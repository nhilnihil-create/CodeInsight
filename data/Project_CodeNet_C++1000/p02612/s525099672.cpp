#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int INF = 1001001001;
using ll = long long;


int main() {
  int a;
  cin >> a;
  int ans;
  ans = a % 1000;
  if(ans==0) cout << ans << endl;
  else{
    cout << 1000 - ans << endl;
  }
  return 0;
}