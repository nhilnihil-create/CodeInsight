#include <bits/stdc++.h>
#define LL int
using namespace std;
const int mod = 998244353;
const int maxn = 3010;
int dp[maxn];
void add(int &x ,int y){
  x+=y;
  if(x>=mod) x-=mod;
}
int main(){
  	int n,s,x;
  	cin>>n>>s;
  
  	dp[0] = 1;
  	for (int i=1;i<=n;i++){
      cin>>x;
      for (int j=s;j>=x;j--){
      	add(dp[j],dp[j]);
        add(dp[j],dp[j-x]);
      }
      for (int j=x-1;j>=0;j--) add(dp[j],dp[j]);
    }
  	cout<<dp[s]<<endl;
	return 0;
}