#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n, k;
  cin >> n >> k;

  vector<double> cum(n+1,0);

  rep(i,n){
    double p;
    cin >> p;

    double e=0;
    rep(i,p+1){
      if(i==0) continue;
      e += i/p;
    }
    cum[i+1] = cum[i]+e;
  }

  double ans = 0;

  rep(i,n-k+1) ans = max(ans, cum[i+k]-cum[i]);
  printf("%.7f", ans);
  
}
