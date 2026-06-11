#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int x;
  cin >> x;
  int cnt500, cnt5;
  cnt500 = x / 500;
  cnt5 = (x - x / 500 * 500) / 5;
  int ans = cnt500 * 1000 + cnt5 * 5;
  cout << ans << endl;
  return 0;
}
