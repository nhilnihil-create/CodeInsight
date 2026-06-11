#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;

    

int main(){
  ll N,ans=0;
  cin >> N;
  vector<vector<ll>> dp(10, vector<ll>(10,0));
  rep(i,N){
    ll x,y;
    y=(i+1)%10;
    if((i+1)/100000>0){
      x=(i+1)/100000;
    }else if((i+1)/10000>0){
      x=(i+1)/10000;
    }else if((i+1)/1000>0){
      x=(i+1)/1000;
    }else if((i+1)/100>0){
      x=(i+1)/100;
    }else if((i+1)/10>0){
      x=(i+1)/10;
    }else{
      x=i+1;
    }
    dp.at(x).at(y)++;
  }
  for(ll i=1;i<10;i++){
    for(ll j=1;j<10;j++){
      ans+=dp.at(i).at(j)*dp.at(j).at(i);
    }
  }
  cout << ans << endl;
    
  
}
