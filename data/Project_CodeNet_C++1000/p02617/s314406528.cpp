#include<bits/stdc++.h>
using namespace std;

const int N=500005;
int n;
long long ans;

int main()
{
	scanf("%d",&n),ans=n;
	for(int i=1;i<n;i++)
	{
		ans+=1ll*i*(n-i+1);
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		ans-=1ll*x*(n-y+1);
	}
	printf("%lld\n",ans);
}