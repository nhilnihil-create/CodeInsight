#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int a[200200]; 
int main() {
  int n;
  cin >> n;
  rep(i,n) cin >> a[i];
  ll all = 0;
  rep(i,n) all = all ^ a[i];
  rep(i,n) {
    ll now = all ^ a[i];
    cout << now << ' ';
  }
  cout << endl;
  return 0;
}