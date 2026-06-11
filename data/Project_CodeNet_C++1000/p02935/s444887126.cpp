#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int N;cin>>N;
  vector<double> v(N);rep(i,N) cin>>v[i];
  
  sort(v.begin(),v.end());
  
  double ans=v[0];
  for(int i=0;i<N;i++){
    ans+=v[i+1]*pow(2,i);
  }
  ans/=pow(2,N-1);
  
  cout << fixed << setprecision(6) << ans << endl;
}
 