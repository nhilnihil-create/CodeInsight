#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,r; cin >> n >> r;
  int ans=r;
  
  if(n<10) ans = r+100*(10-n);

  cout << ans << endl;
  
  return 0;
}
