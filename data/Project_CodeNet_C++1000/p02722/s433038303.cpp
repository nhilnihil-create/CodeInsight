#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll>P;

int main(){
  ll N;cin>>N;
  ll n=N-1;
  //N-1の約数列挙
   vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
 //Nの約数列挙
  vector< ll > reta;
  for(ll i = 1; i * i <= N; i++) {
    if(N% i == 0) {
      reta.push_back(i);
      if(i * i != N) reta.push_back(N / i);
    }
  }
  sort(begin(reta), end(reta));
  
  ll ans=0;
  rep(i,ret.size()){
  	if(N%ret[i]==1){ans++;}
  }
  rep(i,reta.size()){
  	ll p=N;
    ll q=reta[i];
    if(q==1){continue;}
    while(p%q==0){
      p/=q;
    }
    if(p%q==1){ans++;}
  }
  cout<<ans;
}
