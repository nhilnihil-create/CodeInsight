#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 10010;

int main(void){
  int a, b;
  cin >> a >> b;
  int ans = INF;
  for(int i = 1; i < 1005; i++){
    if(floor(i*8/100) != a) continue;
    if(floor(i*10/100) != b) continue;
    ans = min(ans, i);
  }
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}