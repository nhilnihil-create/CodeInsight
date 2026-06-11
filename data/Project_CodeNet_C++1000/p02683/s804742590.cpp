#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fastin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int inf=0x3f3f3f3f;
int n,m,x,c[20],a[20][20],ans=inf;
int v[20];
void dfs(int now,int sumc){
	if(now==n+1){
		int flag=1;
		rep(i,1,m){
			if(v[i]<x){
				flag=0;break;
			}
		}
		if(flag){
			ans=min(ans,sumc);
		}
		return ;
	}
	dfs(now+1,sumc);
	rep(i,1,m)	v[i]+=a[now][i];
	dfs(now+1,sumc+c[now]);
	rep(i,1,m)	v[i]-=a[now][i];
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	rep(i,1,n){
		scanf("%d",&c[i]);
		rep(j,1,m)	scanf("%d",&a[i][j]);
	}
	dfs(1,0);
	if(ans==inf)	ans=-1;
	printf("%d\n",ans);
	return 0;
}