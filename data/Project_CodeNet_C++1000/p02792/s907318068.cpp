// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int ms(int n) {
  while (n/10 > 0) n/=10;
  return n;
}

int ls(int n) {
  return n % 10;
}

int main() {
  int n; cin >> n;
  int C[10][10];
  memset(C, 0, sizeof(C));
  loop(i,1,n+1) {
    C[ms(i)][ls(i)]++;
  }
  
  ll ans = 0;
  loop(i,0,10) loop(j,0,10) ans += C[i][j] * C[j][i];
  cout << ans << endl;
  return 0;
}
