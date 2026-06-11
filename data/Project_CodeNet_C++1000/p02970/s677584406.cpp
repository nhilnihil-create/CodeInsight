#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,d; cin >> n >> d;

  int ans;
  for(int i = 1;i<=n;i++){
    if(i*(1+2*d)>=n){
      ans = i;
      break;
    }
  }

  cout << ans << endl;
  
  return 0;
}
