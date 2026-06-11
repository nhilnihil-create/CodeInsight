#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000000;
//------------------------------------------//

int main(){
  double N;cin>>N;
  vector<double> v(N);
  rep(i,N) cin>>v[i];
  sort(v.begin(),v.end());
  double ans=(v[0]+v[1])/2;
  if(N>2){
    for(int i=2;i<N;i++){
      ans=(ans+v[i])/2;
    }
  }
  cout<<fixed<<setprecision(7)<<ans<<endl;
}