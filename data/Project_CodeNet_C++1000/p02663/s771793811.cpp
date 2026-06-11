#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h1,m1,h2,m2,k,t;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  t = (h2-h1)*60+m2-m1;
  int ans = t-k;
  cout << ans << endl;
}