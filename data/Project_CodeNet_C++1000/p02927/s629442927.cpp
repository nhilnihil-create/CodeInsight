#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int m,d;
cin >> m >> d;
  int ans = 0;
    for(int j = 22; j <= d; j++){
      int t = j;
      int x = t%10;
      t /= 10;
      int y = t%10;
      if(x>1 && y>1 && x*y <= m) ans++;
    }
  cout << ans << endl;
}
