#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<double> v(n); rep(i,n) cin >> v[i];

  sort(v.begin(),v.end());
  double ans = v[0]+v[1];
  ans *= 0.5;
  for(int i = 2;i<n;++i){
    ans = ans+v[i];
    ans *= 0.5;
  }
  printf("%.10f\n",ans);
  
  return 0;
}
