#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
int s;

const int mod=1e9+7;
void add(int &x,int y){
  x+=y;
  if(x>=mod)x-=mod;
}
int dp[N];
int main() {
  ios::sync_with_stdio(false);
  cin>>s;dp[0]=1;
  for(int i=0;i<=s;i++){
    for(int j=3;j+i<=s;j++){
      add(dp[j+i],dp[i]);
    }
  }
  cout<<dp[s]<<'\n';
  return 0;
}
