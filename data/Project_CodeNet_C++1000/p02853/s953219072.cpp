#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int M = 1e7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  int x,y;
  cin >> x >> y;

  if (x == 1 && y == 1){ 
    cout << 1000000 << endl;
    return 0;
  }

  int ans = 0;
  if (x == 1) ans += 300000;
  if (x == 2) ans += 200000;
  if (x == 3) ans += 100000;  
  if (y == 1) ans += 300000;
  if (y == 2) ans += 200000;
  if (y == 3) ans += 100000;
  cout << ans << endl;
  return 0;
}
