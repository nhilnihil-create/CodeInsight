#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAX=100010;
const ll MOD=1e+9+7;
void add(ll &a,ll b){
  a+=b;
  if(a>=MOD){
    a-=MOD;
  }
}
int main(){
  string s;
  cin>>s;
  vector<vector<ll>>dp(MAX,vector<ll>(13,0));
  dp[0][0]=1;
  for(ll i=0;i<s.size();i++){
    for(ll j=0;j<13;j++){
      if(s.at(i)=='?'){
        for(ll k=0;k<10;k++){
          add(dp[i+1][(j*10+k)%13],dp[i][j]);
        }
      }else{
        ll k=s.at(i)-48;
        add(dp[i+1][(j*10+k)%13],dp[i][j]);
      }
    }
  }
  cout<<dp[s.size()][5]<<endl;

}