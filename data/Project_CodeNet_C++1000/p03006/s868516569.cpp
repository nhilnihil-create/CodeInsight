#include <bits/stdc++.h>
using namespace std;

const int maxn=51,INF=1e9;
int n,x[maxn],y[maxn],used[maxn];

int solve(int p,int q){
	memset(used,0,sizeof(used));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (x[i]+p==x[j] && y[i]+q==y[j])
				used[j]=1;
	return n-accumulate(used,used+n,0);
}

int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>x[i]>>y[i];
	int ans=INF;
	if (n==1) ans=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			if (i==j) continue;
			ans=min(ans,solve(x[j]-x[i],y[j]-y[i]));
		}
	printf("%d\n",ans);
	return 0;
}