#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vector<bool> t(n+1, false);
  vector<int> x(n+1);

  x[0] = 1;
  t[1] = true;
  int ans;
  for (int i = 1; i <= n+1; i++) {
    if (i == k) {
      ans = a[x[i-1]];
      break;
    }
    if (t[a[x[i-1]]]) {
      auto itr = find(x.begin(), x.end(), a[x[i-1]]);
      int index = distance(x.begin(), itr);
      //cout << index << endl;
      int num = (k-i)%(i-index);
      //cout << num << endl;
      ans = x[index+num];
      break;
    }
    x[i] = a[x[i-1]];
    t[x[i]] = true;
  }

  cout << ans << endl;
  
  return 0;
}