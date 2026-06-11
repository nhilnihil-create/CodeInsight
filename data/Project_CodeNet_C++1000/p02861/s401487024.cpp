#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> x(n),y(n),vec(n);
  rep(i,n){
    cin>>x[i]>>y[i];
    vec[i]=i;
  }
  double ans=0;int cnt=0;
  do{
    rep(i,n-1){
      double dx=x[vec[i]]-x[vec[i+1]],dy=y[vec[i]]-y[vec[i+1]];
      ans+=sqrt(dx*dx+dy*dy);
    }
    cnt++;
  }while(next_permutation(all(vec)));
  ans/=cnt;
  cout<<fixed<<setprecision(10)<<ans<<endl;
}