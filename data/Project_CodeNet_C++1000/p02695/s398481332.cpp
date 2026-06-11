#include<bits/stdc++.h>
#define ll long long
const int N=100005;
using namespace std;
int A[15],n,m,q,a[55],b[55],c[55],d[55],ans;
void dfs(int dep,int pre)
{
	if(dep==n)
	{
		int sum=0;
		for(int i=0;i<q;i++)
		    if(A[b[i]]-A[a[i]]==c[i]) sum+=d[i];
		ans=max(ans,sum);
		return;
	}
	for(int i=pre;i<=m;i++)
	{
		A[dep]=i;
		dfs(dep+1,i);
	}
}
int main(){
	cin>>n>>m>>q;
	for(int i=0;i<q;i++)
	    cin>>a[i]>>b[i]>>c[i]>>d[i],a[i]--,b[i]--;
	dfs(0,1);
	cout<<ans;
    return 0;
}