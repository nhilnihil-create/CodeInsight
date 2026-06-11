#include<bits/stdc++.h>
using namespace std;
int a[2005][2005];
void solve(int l,int r,int dep){
	if(l==r) return;
	int mid=(l+r)>>1;
	for(int i=l;i<=mid;++i)
		for(int j=mid+1;j<=r;++j)
			a[i][j]=dep;
	solve(l,mid,dep+1);
	solve(mid+1,r,dep+1);
}
signed main(){
	int n;
	cin>>n;
	solve(1,n,1);
	for(int i=1;i<=n;++i,puts(""))
		for(int j=i+1;j<=n;++j,putchar(' '))
			cout<<a[i][j];
	return 0;
}