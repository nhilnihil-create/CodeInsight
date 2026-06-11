#include <bits/stdc++.h>
#define rep(i, n, k) for(int i = k; i < n; ++i)
#define mod 1000000007
using namespace std;

int main() {
  int m, d;
  cin >> m >> d;
  int a, b;
  long long int ans = 0;
  rep(i,m+1,1){
    rep(j,d+1,1){
      a = j / 10;
      b = j % 10;
      if(i == a*b && a > 1 && b > 1) ans++;
    }
  }
  cout << ans << endl;
}