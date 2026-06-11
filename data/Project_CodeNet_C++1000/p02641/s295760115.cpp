#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int x, n;
  cin >> x >> n;
  vector<bool> ng(102,false);
  rep(i,n){
    int p;
    cin >> p;
    ng[p] = true;
  }
  P ans(99999,-1);
  rep(i,102){
    if(ng[i]) continue;
    int dif = abs(x-i);
    ans = min(ans, P(dif, i));
  }
  cout << ans.second << endl;
  return 0;
}