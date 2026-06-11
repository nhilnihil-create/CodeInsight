#include <bits/stdc++.h>
// #include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=(a);i<(b);i++)
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}
const ll inf = 1LL<<60;



int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  string s;cin>>s;
  const ll mod =pow(10,9)+7;
  vector<vector<ll>> dp(s.size()+1,vector<ll>(13,0));

  dp[0][0]=1;
  for(ll i=0; i<s.size();i++){
    if(s[i]=='?'){
      for(int j=0;j<13;j++){
        for(int k=0;k<10;k++){
          dp[i+1][(j*10+k)%13]=(dp[i+1][(j*10+k)%13]+dp[i][j])%mod;
        }
      }
    }else{
      for(int j=0;j<13;j++){
        int k=s[i]-'0';
        dp[i+1][(j*10+k)%13]=(dp[i+1][(j*10+k)%13]+dp[i][j])%mod;
      }
    }
  }
  cout<<dp[s.size()][5]<<endl;
}
