#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main()
{
	int n;
	ll res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)res+=1ll*(n-i+2)*(n-i+1)/2;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);
		res-=1ll*u*(n-v+1);
	}
	printf("%lld\n",res);
	return 0;
}
