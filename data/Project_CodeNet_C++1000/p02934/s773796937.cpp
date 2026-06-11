#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  double ans = 0;
  rep(i,n) ans+=1./(double)a[i];
  
  ans = 1./ans;
  
  printf("%.9f\n",ans);
  
  return 0;
}
