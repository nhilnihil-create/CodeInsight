#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,tot = 0;
  cin >> n;
  vector<int> w(n);
  rep(i,n) {
    cin >> w[i];
    tot += w[i];
  }
  int sum = 0,k,ans = 1000000;
  rep(i,n){
    sum += w[i];
    k = abs(tot - 2*sum);
    ans = min(ans, k);
  }

  cout << ans << endl;
  return 0;


}