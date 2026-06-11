//Powered by caibiCH2 at 2020/04/24,19:58:15
#include<bits/stdc++.h>
#define elif else if
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f;
ll f[2010][2010];
struct msp{
	ll num,data;
}a[2010];
inline ll cal(int cx,int wz){
	return abs(wz-a[cx].num)*a[cx].data;
}
signed main(){
	ios::sync_with_stdio(0);
	//cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].data;a[i].num=i;
	}
	sort(a+1,a+n+1,[](const msp&x,const msp&y){
		return x.data>y.data;
	});
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n-i;++j){
			int now=i+j;
			if(i==0&&j==0)continue;
			elif(i==0){
				f[i][j]=f[i][j-1]+cal(now,n-j+1);
			}
			elif(j==0){
				f[i][j]=f[i-1][j]+cal(now,i);
			}
			else{
				f[i][j]=max(f[i][j-1]+cal(now,n-j+1),f[i-1][j]+cal(now,i));
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n;++i){
		ans=max(ans,f[i][n-i]);
	}
	cout<<ans<<'\n';
	return 0;
}