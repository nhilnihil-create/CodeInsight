#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int a, b, ans;
  cin >> a >> b;
  
  rep(i, 10){
    ans = b*10 + i;
    if((ans*8)/100 == a){
      cout << ans << endl;
      return 0;
    }
  }
  
  cout << -1 << endl;
  
return 0;
}