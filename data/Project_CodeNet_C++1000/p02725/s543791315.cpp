#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 

int main() {
  int k, n;
  cin >> k >> n;
  int x = 0;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0) continue;
    x = max(x, a[i]-a[i-1]);
  }
  x = max(x, k-a[n-1]+a[0]);
  cout << k-x << endl;
  return 0;
}