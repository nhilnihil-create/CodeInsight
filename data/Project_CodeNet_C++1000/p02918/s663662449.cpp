#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,k; string s;
  cin >> n >> k >> s;
  int p = 0;
  rep(i,0,n-1) {
    if (s[i] != s[i+1]) {
      p++;
    }
  }
  p = max(0, p-2*k);
  cout << n-p-1 << endl;
  return 0;
}
