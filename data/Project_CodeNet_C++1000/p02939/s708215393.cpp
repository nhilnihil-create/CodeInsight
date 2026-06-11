#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
const int maxn=2e5+5;
string s;
int n,vis[maxn],ans;
int dp[maxn][2];
string a[maxn][2];
int main(){
	cin>>s;
	n=s.size();
	s=" "+s;
	string last="";
	for (int i=1;i<=n;i++){
		if (i>=2){
			a[i][1]="  ";
			a[i][1][0]=s[i-1],a[i][1][1]=s[i];
		}
		a[i][0]=" ";
		a[i][0][0]=s[i];
	}
	memset(dp,0xf3,sizeof(dp));
	dp[0][0]=dp[0][1]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=1;j++){
			for (int k=0;k<=1;k++){
				//cout<<"print i "<<i-1-j<<endl;
				if (j!=k) {
					if (i-1-j>=0) dp[i][j]=max(dp[i][j],dp[i-1-j][k]+1);
				}
				else if (i-1-k>=0&&a[i][j]!=a[i-1-j][k]) dp[i][j]=max(dp[i][j],dp[i-1-j][k]+1);
			}
		}
	}
	cout<<max(dp[n][0],dp[n][1])<<endl;
}