#include<bits/stdc++.h>
using namespace std;
int a[15];
struct node{
	int a,b,c,d;
}q[55];
int N,M,Q,res=0;
void dfs(int ans,int id)
{
	if(ans>N)
	{
		int sum=0;
		for(int i=1;i<=Q;i++)
		{
			if(a[q[i].b]-a[q[i].a]==q[i].c)
			sum+=q[i].d;
		}
		res=max(res,sum);
	}
	else
	{
		for(int i=id;i<=M;i++)
		{
			a[ans]=id;
			dfs(ans+1,i);
		}
	}
}
int main()
{
	cin>>N>>M>>Q;
	for(int i = 1;i<=Q;i++){
		cin>>q[i].a >> q[i].b >> q[i].c>>q[i].d;
	}
	dfs(1,1);
	cout<<res<<endl;;
}
 