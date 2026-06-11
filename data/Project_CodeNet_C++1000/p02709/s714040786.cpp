#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n;
struct node{
	int val;
	int id;
	bool operator<(node x)const{
		return val>x.val;
	}
}a[2010];
int dp[2010][2010];
signed main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			const int k=i+j+1;
			if(k>n)
				break;
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[k].val*abs(a[k].id-(i+1)));
			dp[i][j+1]=max(dp[i][j+1],dp[i][j]+a[k].val*abs(a[k].id-(n-j)));
		}
	int maxv=0;
	for(int i=0;i<=n;++i)
		maxv=max(maxv,dp[i][n-i]);
	cout<<maxv<<endl;
	return 0;
}