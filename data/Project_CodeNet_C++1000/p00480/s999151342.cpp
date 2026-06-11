#include <iostream>
using namespace std;

typedef long long ll;

ll dp[101][21];
int n, num[101];

ll rec(int idx, int sum){
  if(idx == n-1) return (sum == num[idx]);
  if(sum < 0 || sum > 20) return 0;
  if(dp[idx][sum]) return dp[idx][sum];
  
  return dp[idx][sum] = (rec(idx+1, sum+num[idx]) + rec(idx+1, sum-num[idx]));
}

int main(){
  
  cin >> n;
  for(int i = 0; i < n; i++) cin >> num[i];
  
  cout << rec(1, num[0]) << endl;
}