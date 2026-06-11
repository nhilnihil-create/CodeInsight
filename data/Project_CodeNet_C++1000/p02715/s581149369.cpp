#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
ll N,K;

map<ll,ll> M;
ll zyou(ll x) {
  if(M.count(x)) {
return M[x];
  }
  
ll i=1;
  ll k=x;
  ll num=1000000007;
  while(i<N) {
x*=k;
    i++;
    x%=num;
  }
  M[k]=x;
  return x;
}
int main() {
  
  cin>>N>>K;

  vector<ll> vec(K+1);
  for(ll i=0;i<K;i++) {
    ll bai=K/(K-i);
    ll a=zyou(bai);

ll j=2;
    while(bai-1>0) {
      a-=vec[(K-i)*j];
      bai--;
      j++;
    }
    vec[K-i]=a;
  }
  ll ans=0;
  for(ll i=1;i<=K;i++) {
    ans+=vec[i]*i;
    if(ans>1000000007) {
ans%=1000000007;
    }
  }
  
  cout<<ans<<endl;
}

  


  
  