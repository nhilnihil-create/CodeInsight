#include<bits/stdc++.h>
#define max 1000000000
using namespace std;
int n,m;
int cost[1000];
int num[1000];
int keys[1000][12];
int visited[1000][5000];
int memo[1000][5000];
int dp(int pos,int arg)
{
//	cout<<"pos "<<pos<<" arg "<<arg<<" ";
	if(arg == (pow(2,n)-1))
	 return 0;
	if(pos==m)
	 return max;
	if(visited[pos][arg])
	 return memo[pos][arg];
	visited[pos][arg]=1;
	int cost1=dp(pos+1,arg);
	int var=arg;
	for(int i=0; i<num[pos]; i++)
	{
		int temp=keys[pos][i]-1;
		var=(var)|(1<<temp);
	}
	int cost2=cost[pos]+dp(pos+1,var);
	memo[pos][arg]=min(cost1,cost2);
	return memo[pos][arg];
}
int main()
{
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>cost[i]>>num[i];
		for(int j=0; j<num[i]; j++)
		 cin>>keys[i][j];
	}
	for(int i=0; i<1000; i++)
	{
		for(int j=0; j<5000; j++)
		 visited[i][j]=0;
	}
	int ans=dp(0,0);
	if(ans>=max)
	 cout<<"-1";
	else
	 cout<<ans;
	return 0;
	
}