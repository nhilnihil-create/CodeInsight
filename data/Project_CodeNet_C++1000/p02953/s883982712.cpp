#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  int now = h[n-1];
  for (int i = n-2; i >= 0; --i) {
    if (h[i] - 1 > now) {
      cout << "No" << endl;
      return 0;
    }
    if (h[i] < now) now = h[i]; 
  }
  cout << "Yes" << endl;
  return 0;
}