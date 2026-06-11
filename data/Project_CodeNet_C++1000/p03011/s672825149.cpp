#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int p,q,r; cin >> p >> q >> r;

  int ans1=INF,ans2=INF;
  ans1 = min(p+q,r+q);
  ans2 = min(r+p,q+p);
  int ans = min(ans1,ans2);
  cout << ans << endl;
  
  return 0;
}
