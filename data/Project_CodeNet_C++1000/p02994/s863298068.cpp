#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,l;
  cin >> n >> l;
  int a = 0;
  rep(i,0,n) {
    a += i+l;
  }
  if (l > 0) {
    a -= l;
  } else if (l+n-1 < 0) {
    a -= l+n-1;
  }
  cout << a << endl;
  return 0;
}
