#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<double> x(n),y(n); rep(i,n) cin >> x[i] >> y[i];
  vector<int> a(n);
  rep(i,n) a[i] = i;
  
  double ans = 0.0;
  int cnt = 0;
  do{
    /*vector<int> test(n);
    rep(i,n) test[i] = a[i];
    sort(test.begin(),test.end());
    test.erase(unique(test.begin(),test.end()),test.end());
    if(test.size()!=n) continue;*/

    double dist=0.0;
    rep(i,n-1){
      double tmp;
      tmp = (x[a[i]]-x[a[i+1]])*(x[a[i]]-x[a[i+1]])+(y[a[i]]-y[a[i+1]])*(y[a[i]]-y[a[i+1]]);
      tmp = sqrt(tmp);
      dist+=tmp;
    }
    ans += dist;
    //cout << ans << endl;
    cnt++;
  }while(next_permutation(a.begin(),a.end()));  

  ans = ans/(double)cnt;
  printf("%.10f\n",ans);
  
  return 0;
}
