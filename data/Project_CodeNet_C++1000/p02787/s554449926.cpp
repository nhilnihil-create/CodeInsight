#include<bits/stdc++.h>

using namespace std;

int dp[10001];
int n,h,a[1000],b[1000];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h,n;
	cin >> h >> n;
	
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	memset(dp,0x3f,sizeof(dp)); 
	dp[0]=0;	
	for(int i=0;i<n;i++){
		int c=a[i];
		int p=b[i];
		for(int j=1;j<=h;j++){
			if(j < c)
				dp[j]=min(dp[j],p);
			else 
				dp[j]=min(dp[j],dp[j-c]+p);
		}
	}
	cout<<dp[h];
}