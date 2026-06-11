#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  int c[3] = {0,0,0};
  ll ans = 1;
  for(int i=0; i<n; ++i){
    int cnt = 0;
    int cnum = 3;
    if(c[0] == an[i]){ ++cnt; cnum = 0;}
    if(c[1] == an[i]){ ++cnt; cnum = 1;}
    if(c[2] == an[i]){ ++cnt; cnum = 2;}
    if(cnum == 3){ ans = 0; break;}
    ++c[cnum];
    ans *= cnt;
    ans %= MOD;
  }
  cout << ans << endl;
}