#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  ll n;
  std::cin >> n;
  std::vector<ll> v(n);

  ll tot=0;
  rep(i,n){
    std::cin >> v[i];
    tot+=v[i];
  }

  ll ntot=0;
  rep(i,n){
    if(ntot+v[i]<=tot/2)ntot+=v[i];
    else {
      // std::cout << "ntot"<<ntot << '\n';

      ll ans=tot-2*ntot;
      if(ans<0)ans*=-1;
      // std::cout << "ans:" <<ans<<'\n';

      if(i+1<n)ntot+=v[i];
      // std::cout << "ntot" <<ntot<<'\n';
      ll ans2=2*ntot-tot;
      if(ans2<0)ans2*=-1;

      // std::cout << "ans2:" << ans2<< '\n';

      if(ans>ans2)ans=ans2;

      std::cout << ans << '\n';




      return 0;
    }
  }

  return 0;
}
