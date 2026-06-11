#include<bits/stdc++.h>
using namespace std;

#define mod      1e9+7;
#define INF      1e9+9;
#define ps(x,y)  fixed<<setprecision(y)<<x
# define PI 3.14159265358979323846264338327950 L
typedef long long ll;
typedef unsigned long long ull;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	int health,n;
	cin>>health>>n;
	int pow[n],cost[n];
	for(int i=0;i<n;i++)
		cin>>pow[i]>>cost[i];
	int dp[health+1];
	for(int i=0;i<=health;i++)
		dp[i]=INT_MAX;
	dp[0]=0;
	for(int i=1;i<=health;i++){
		for(int j=0;j<n;j++){
			//if(i==7)
			//cout<<dp[i]<<' '<<cost[j]<<' '<<j<<endl;
			if(i-pow[j]<=0)
				dp[i]=min(dp[i],cost[j]);
			else{
				dp[i]=min(dp[i],dp[i-pow[j]]+cost[j]);
			}
			//if(i==7)
				//cout<<dp[i]<<' '<<i<<' '<<pow[j]<<endl;
		}
	}
//	for(int i=0;i<=177;i++)
//		cout<<dp[i]<<' ';
	cout<<dp[health]<<endl;
	return 0;
}