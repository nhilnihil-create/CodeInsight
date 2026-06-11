#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;




int main(){
  ll n;
  cin >>n;
  vector<ll> div1,div2;//約数
  
  ll ans=0;
  // n-1の約数を求める．
  for(ll k=2; k*k<= n; k++){
    if((n-1)%k==0 && k*k<=n-1){
      div1.emplace_back(k);
      if (k!=(n-1)/k){
        div1.emplace_back((n-1)/k);
        ans+=2;
      }else{
        ans++;
      }
    }
    
    if(n%k==0){
      div2.emplace_back(k);
      
      if (k!=n/k){
      	div2.emplace_back(n/k);
      }
    }
  }
  if (n>2){
  	div1.emplace_back(n-1);
	ans++;
  }
  
  div2.emplace_back(n);
  
  
  
  for(ll k: div2){
    bool so=false;
    ll n1=n;
    while(!so){
      if(n1%k==0){
        n1 /=k;
      }else{
        so=true;
      }
    }
    if (n1%k==1) ans++;
    
  }
  

  cout<<ans<<endl;
  return 0;
  
}
