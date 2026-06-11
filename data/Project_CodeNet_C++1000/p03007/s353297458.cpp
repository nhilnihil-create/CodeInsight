#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cassert>
#include <string>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll A[SIZE];
int sgn[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
	int mn=0,pl=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]>=0) pl++;
		if(A[i]<=0) mn++;
	}
	if(pl==0)
	{
		ll mx=A[0];
		for(int i=0;i<n;i++) mx=max(mx,A[i]);
		for(int i=0;i<n;i++)
		{
			if(mx==A[i])
			{
				sgn[i]=1;
				mx=0;
			}
			else sgn[i]=-1;
		}
	}
	else if(mn==0)
	{
		ll mn=A[0];
		for(int i=0;i<n;i++) mn=min(mn,A[i]);
		for(int i=0;i<n;i++)
		{
			if(mn==A[i])
			{
				sgn[i]=-1;
				mn=0;
			}
			else sgn[i]=1;
		}
	}
	else
	{
		pl=mn=0;
		for(int i=0;i<n;i++)
		{
			if(A[i]>0)
			{
				sgn[i]=1;
				pl++;
			}
			else if(A[i]<0)
			{
				sgn[i]=-1;
				mn++;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(A[i]==0)
			{
				if(pl==0)
				{
					sgn[i]=1;
					pl++;
				}
				else sgn[i]=-1;
			}
		}
	}
	ll ret=0;
	queue <int> vp,vm;
	for(int i=0;i<n;i++)
	{
		if(sgn[i]==1)
		{
			ret+=A[i];
			vp.push(i);
		}
		else
		{
			ret-=A[i];
			vm.push(i);
		}
	}
	printf("%lld\n",ret);
	while(vp.size()>=2)
	{
		int v=vp.front();vp.pop();
		int u=vm.front();vm.pop();
		printf("%lld %lld\n",A[u],A[v]);
		A[u]-=A[v];
		vm.push(u);
	}
	while(vm.size()>=1)
	{
		int v=vp.front();vp.pop();
		int u=vm.front();vm.pop();
		printf("%lld %lld\n",A[v],A[u]);
		A[v]-=A[u];
		vp.push(v);
	}
	return 0;
}
