#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define ll long long
using namespace std;



int main() {
  int n, m, k=0;
  cin >> n >> m;
  rep(i, m){
    int a;
    cin >> a;
    k += a;
  }
  n -= k;
  if(n < 0) cout << -1 << endl;
  else cout << n << endl;
  return 0;
}
