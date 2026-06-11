#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<int> dp(n+1);
    int r = n;
    for(int i = n-1; i >= 0; i--){
      if(s[i] == '1'){
        dp[i] = -1;
        continue;
      }
      while(r>i+m) r--;
      while(dp[r] == -1) r--;
      if(i == r){
        cout<<-1;
        return 0;
      }
      dp[i] = dp[r]+1;
    }

    vector<int> ans;
    int curr = 0;
    for(int i = 0; i < n+1; i++){
      if(dp[i] == -1) continue;
      if(dp[i]!=dp[curr]){
        ans.push_back(i-curr);
        curr = i;
      }
    }
    for(int i = 0; i < (int)ans.size(); i++) cout<<ans[i]<<" ";
    
}
