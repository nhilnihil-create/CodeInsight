#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int n,m;
  cin >> n >> m;
  cout << n*(n-1)/2 + m*(m-1)/2 << endl;
  return 0;
}