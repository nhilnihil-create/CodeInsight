#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char c[2020][2020];
ll cnt[4][2020][2020];
int main(){
	ll h,w;
	cin>>h>>w;
	for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)cin>>c[i][j];
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(c[i][j]=='#')cnt[0][i][j]=0;
			else cnt[0][i][j]=cnt[0][i][j-1]+1;
			if(c[i][w+1-j]=='#')cnt[1][i][w+1-j]=0;
			else cnt[1][i][w+1-j]=cnt[1][i][w+2-j]+1;
		}
	}
	for(int i=1;i<=w;i++){
		for(int j=1;j<=h;j++){
			if(c[j][i]=='#')cnt[2][j][i]=0;
			else cnt[2][j][i]=cnt[2][j-1][i]+1;
			if(c[h+1-j][i]=='#')cnt[3][h+1-j][i]=0;
			else cnt[3][h+1-j][i]=cnt[3][h+2-j][i]+1;
		}
	}
	// for(int k=0;k<4;k++){
	// 	for(int i=1;i<=h;i++){
	// 		for(int j=1;j<=w;j++)cout<<cnt[k][i][j]<<' ';
	// 		cout<<endl;
	// 	}
	// 	cout<<endl;
	// }
	ll ans=0;
	for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
		ll sum=-3;
		for(int k=0;k<4;k++)sum+=cnt[k][i][j];
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
