#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,ans=0;
  string S;
  cin >> N >> S;
  vector<vector<ll>> Z(S.size(),vector<ll>(S.size()));
  rep(l,S.size()){
    Z.at(l).at(l)= S.size()-l;
    ll i=1,j=0;
    while(i<S.size()-l){
      while(i+j<S.size()-l&&S.at(l+j)==S.at(l+i+j)) j++;
      Z.at(l).at(l+i)=j;
      if(j==0){
        i++;
        continue;
      }
      ll k=1;
      while(k<j&&k+Z.at(l).at(l+k)<j){
        Z.at(l).at(l+i+k)=Z.at(l).at(l+k);
        k++;
      }
      i+=k;
      j-=k;
    }
  }
  rep(l,S.size()-1){
    for(ll i=l+1;i<S.size();i++){
      if(Z.at(l).at(i)<=i-l){
        ans=max(ans,Z.at(l).at(i));
      }else{
        ans=max(ans,i-l);
      }
    }
  }
  cout << ans << endl;
      
      
}