#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
vector<int>G[10005];
int V,E,F[10005]={0};
queue<P>Q;
int main()
{
	scanf("%d%d",&V,&E);
	for(int i=0;i<E;i++)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		G[s].push_back(e);
		F[e]=1;
	}
	for(int i=0;i<V;i++)if(!F[i])Q.push(make_pair(i,0));
	memset(F,0,sizeof(F));
	while(!Q.empty())
	{
		P T=Q.front();Q.pop();
		int s=T.first,t;
		for(int i=0;i<G[s].size();i++)
		{
			t=G[s][i];
			if(F[t]<F[s]+1)
			{
				F[t]=F[s]+1;
				Q.push(make_pair(t,F[t]));
			}
		}
	}
	for(int i=0;i<V;i++)
	{
		int t=-1;
		for(int i=0;i<V;i++)
		{
			if(t==-1||F[t]>F[i])
				t=i;
		}
		printf("%d\n",t);
		F[t]=100000;
	}
}