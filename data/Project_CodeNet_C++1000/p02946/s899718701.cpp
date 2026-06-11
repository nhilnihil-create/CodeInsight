#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int k,x;
  cin >> k >> x;
  rep(i,x-k+1,x+k-1) cout << i << " ";
  cout << x+k-1 << endl;
  return 0;
}
