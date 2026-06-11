#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

ll fact(ll a){
  ll ret = 1;
  while(a>=1){
    ret *= a;
    a--;
  }
  return ret;
}

long double dist(ll x1,ll y1,ll x2,ll y2){
  return pow(double((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)),0.5);
}

int main(){
  int N;cin>>N;
  vll x(N),y(N);rep(i,N)cin>>x[i]>>y[i];
  long double ans = 0;
  for(int i=0;i<N-1;++i){
    for(int j=i+1;j<N;++j){
      ans += 2 * fact(N-1) * dist(x[i],y[i],x[j],y[j]);
    }
  }
  ans /= double(fact(N));
  cout << setprecision(15)<<ans<<endl;
}