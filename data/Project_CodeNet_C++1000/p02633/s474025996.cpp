#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x;
  cin >> x;
  int ans = 1;
  do {
    ans++;
  } while((ans*x) % 360 != 0);
  cout << ans << endl;
  return 0;
}
