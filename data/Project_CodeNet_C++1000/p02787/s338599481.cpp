// 解説に倣ってDP
#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,n;
  cin>> h >> n;
  vector<vector<int>> magic(n,vector<int>(2));
  for(int i=0; i<n; i++) cin>> magic[i][0] >> magic[i][1];
  
  sort(magic.begin(),magic.end());
  int impossible=1e9;
  vector<int> dp(h+1,impossible); dp[0]=0; // dp[i]:体力をi減らすために消耗する魔力の最小値
  for(int i=0; i<h; i++){
    if(dp[i]==impossible) continue;
    for(int j=0; j<n; j++){
      int index= i+magic[j][0]<h ? i+magic[j][0] : h;
      if(dp[index]>dp[i]+magic[j][1]){
        dp[index]=dp[i]+magic[j][1];
      }
    }
  }
  cout<< dp[h] <<endl;
}