#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> d1(n), d2(n);
  rep(i,n)cin >> d1[i] >> d2[i];
  int c=0, m=0, cnt=0;
  rep(i, n){
    if (d1[i] == d2[i]){
      c++;
      continue;
    }else{
      m = max(c, m);
      c = 0;
    }
  }
  m = max(c, m);
  if (m >= 3) cout << "Yes" << endl;
  else cout << "No" << endl;
}