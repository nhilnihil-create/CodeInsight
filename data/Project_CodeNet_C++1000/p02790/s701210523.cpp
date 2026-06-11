#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b; cin >> a >> b;
  string ans;
  
  if(a>=b) rep(i,a) ans+=to_string(b);
  else rep(i,b) ans+=to_string(a);

  cout << ans << endl;
  
  return 0;
}
