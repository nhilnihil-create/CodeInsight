#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
using namespace std;
namespace Solve
{
	const int MAXN=200005;
	int N,K,A[MAXN];
	long long sumv[MAXN];
	int B[MAXN];
	map<int,int>mp;
	void work()
	{
		scanf("%d%d",&N,&K);
		for(int i=1;i<=N;i++)
			scanf("%d",&A[i]);
		sumv[0]=0;
		for(int i=1;i<=N;i++)
			sumv[i]=sumv[i-1]+A[i];
		B[0]=0;
		for(int i=1;i<=N;i++)
			B[i]=(sumv[i]-i)%K;
		long long ans=0;
		mp[0]=1;
		int front=0,rear=1;
		for(int i=1;i<=N;i++)
		{
			rear=i;
			if(rear-front>=K)
			{
				mp[B[front]]--;
				front++;
			}
			if(!mp.count(B[i]))
			{
				mp[B[i]]=1;
			}
			else
			{
				ans+=mp[B[i]];
				mp[B[i]]++;
			}
		}
		cout<<ans<<endl;
		return;
	}
}
int main()
{
	#ifdef LOCAL
	freopen("00test.in","r",stdin);
	freopen("00test.out","w",stdout);
	#endif
	Solve::work(); 
	return 0;
}