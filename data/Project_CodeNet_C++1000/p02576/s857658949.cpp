#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, x, t;
  cin >> n >> x >> t;
  n =(n+x-1)/x;
  cout << (n*t) << endl;
  return 0;
}