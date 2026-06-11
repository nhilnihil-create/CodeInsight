#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int64_t d,a;
  cin>>d>>a;
  vector<pair<int64_t,int64_t>> p(n);
  for(int i=0;i<n;++i) cin>>p[i].first>>p[i].second;
  sort(p.begin(),p.end());

  vector<int64_t> x(n),h(n);
  for(int i=0;i<n;++i) x[i]=p[i].first,h[i]=p[i].second;

  vector<int64_t> dam(n+1,0);
  int64_t ans=0;

  for(int i=0;i<n;++i){
    if(i>0) dam[i] += dam[i-1];

    if(h[i]<=dam[i]) continue;
    else{
      int64_t q=(h[i]-dam[i]+a-1)/a;
      ans += q;
      if(x[i]+2*d>=x[n-1]){
        dam[n] -= q*a;
        dam[i] += q*a;
      }
      else{
      int j=upper_bound(x.begin(),x.end(),x[i]+2*d)-x.begin();
      dam[j] -= q*a;
      dam[i] += q*a;
    }
    }
  }

  cout<<ans<<endl;
}

