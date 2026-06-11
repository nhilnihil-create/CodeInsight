#include<bits/stdc++.h>
typedef long long ll;
#define REP(i,n) for(int i = 0;i < (n);i++)
#define rep(i,m,n) for(int i = (m);i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
#define Vec(a) vector <int> a
const int INF = 1 << 20;
const int MOD = 1e9+7;





int main(){
  int n;
  int res[200] = {};
  res[1] = 1;
  rep(i,2,200){
    res[i] = (res[i-1]*(i+2))/(i-1);
    //cout << i  << "  " << res[i] << endl;
  }
  
  //cout << (180/120*179*178*177*176)/(3*2*1) << endl;
  int dp[2000000] = {};
  int dps[2000000] = {};
  REP(i,1e6+1){
    dp[i] = 100;
    dps[i] = 10000000;
  }
  rep(i,1,181){
    dp[res[i]] = 1;
    if(res[i]%2 == 1){
      dps[res[i]] = 1;
    }
  }
  //cout << dps[5] << endl;
  REP(i,1e6+1){
    for(int j = 1;j < 181;j++){
      if(dp[i] != 0){
	dp[i+res[j]] = min(dp[i+res[j]],dp[i]+1);
	
      }
      if(dps[i] != 0){
	if(res[j]%2 == 1)
	  dps[i+res[j]] = min(dps[i+res[j]], dps[i]+1);
	
      }
      
    }
    
  }
  while(cin >> n, n){

    cout << dp[n] << " " << dps[n] << endl; 

  }
  return 0;
}

