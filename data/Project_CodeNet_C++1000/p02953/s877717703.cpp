#include <bits/stdc++.h>
using namespace std;

int n;
int h[100010];

bool dp[100010];

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> h[i];
  }
  memset(dp,false,sizeof(dp));
  dp[0] = true;
  for(int i = 0; i < n-1; ++i){
    if(h[i] < h[i+1]){
      --h[i+1];
      dp[i+1] = dp[i];
    }else if(h[i] == h[i+1]){
      dp[i+1] = dp[i];
    }else{
      dp[i+1] = false;
    }
  }
  if(dp[n-1]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}