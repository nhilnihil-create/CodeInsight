#include <bits/stdc++.h>
#define LL int
using namespace std;
const int mod = 998244353;
const int maxn = 3010;
int dp[maxn],a[maxn];
void add(int &x ,int y){
  x+=y;
  if(x>=mod) x-=mod;
}
int main(){
  	int n,s,x;
  	cin>>n>>s;
  	for (int i=1;i<=n;i++) cin>>a[i];
  	sort(a+1,a+1+n);
  
  	dp[0] = 1;
  	for (int i=1;i<=n;i++){
      x=a[n-i+1];
      for (int j=s;j>=x;j--){
      	add(dp[j],dp[j]);
        add(dp[j],dp[j-x]);
      }
      add(dp[0],dp[0]);
    }
  	cout<<dp[s]<<endl;
	return 0;
}