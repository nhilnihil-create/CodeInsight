#include <bits/stdc++.h>
using namespace std;
int n;
int ans[503][503];
void dfs(int l,int r,int cnt){
	if (l==r) return;
	int mid=(l+r)/2;
	for (int i=l;i<=mid;i++)
		for (int j=mid+1;j<=r;j++) ans[i][j]=cnt;
	dfs(l,mid,cnt+1);
	dfs(mid+1,r,cnt+1);
}
int main(){
	cin>>n;
	dfs(1,n,1);
	for (int i=1;i<=n-1;i++){
		for (int j=i+1;j<=n;j++) cout<<ans[i][j]<<" ";
		puts("");
	}
}