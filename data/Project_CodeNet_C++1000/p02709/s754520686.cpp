#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
int n;
pair<long long,int> a[2020];
long long dp[2020][2020],res;
void Update(int x,int y,long long val){
	dp[x][y]=max(dp[x][y],val);
}
int main(){
	#ifdef FILIN
		#ifndef LOCAL
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i;
	} 
	sort(a,a+n);
	reverse(a,a+n);
	for(int x=0;x<n;x++){
		for(int y=0;x+y<n;y++){
			Update(x+1,y,dp[x][y]+a[x+y].first*llabs(a[x+y].second-x));
			Update(x,y+1,dp[x][y]+a[x+y].first*llabs(a[x+y].second-(n-1-y)));
		}
	}
	for(int i=0;i<n;i++)
		res=max(res,dp[i][n-i]);
	cout<<res<<endl;
	return 0;
}
