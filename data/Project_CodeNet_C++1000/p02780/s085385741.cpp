#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main() {
  int n,k;
  cin >> n >> k;
  vector<double> p(n);
  rep(i,n) cin >> p[i];
  vector<int> sum(n+1);
  rep(i,n){
    sum[i+1] = sum[i]+p[i];
  }
  //隣接するk個のpが最大の最初のindex
  int index=-1;
  int nax = -1;
  rep(i,n-k+1){
    int now;
    now = max(nax,sum[i+k]-sum[i]);
    if(nax<now){
      index = i;
      nax = now;
    }
  }
  double ans=0;
  rep(i,k)
    ans+=(1+p[index+i])/2.l;
  printf("%.10lf",ans);
  return 0;
}
