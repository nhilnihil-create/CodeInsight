#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 
const int MAX = 510000;
const int MOD = 1000000007;
int main() {
  int h,n;
  cin >> h>>n;
  vector<pair<int,int>>a;
  
  int ta,tb;
  for(int i = 0;i<n;i++){
    cin >> ta >> tb;
    a.push_back(make_pair(ta,tb));
  }
  
  int dp[10001];
  for(int i = 0;i<10001;i++){
    dp[i] = 1000000000;
  }
  
  dp[0] = 0;
  int tmp_a,tmp_b;
  for(int i =1;i<h+1;i++){
    for(int j = 0;j<n;j++){
      tmp_a = a[j].first;
      tmp_b = a[j].second;
      if(i-tmp_a >=0){
        dp[i] = min(dp[i],dp[i-tmp_a]+tmp_b);
      }else{
        dp[i] = min(dp[i],dp[0] + tmp_b);
      }
    }
  }
  cout << dp[h];             
                  
}
