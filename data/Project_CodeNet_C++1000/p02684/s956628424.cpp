#include<functional>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<string>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};// 上 左 下 右
const int N=100005,M=1000005,K=200005,mod=1000000007;
const long long llinf=9223372036854775807ll;
//int & long long
int n,a[K],u[K];
long long k;
vector<int> c;
void findcycle(int b,int e,int x)
{
	c.push_back(x);
	if(x==e)
		return ;
	findcycle(b,e,a[x]);
}
void go(int x,long long now,int last)
{
	if(now==k)
	{
		cout<<x;
		return ;
	}
	if(a[x]==x)
	{
		cout<<x;
		return ;
	}
	if(u[x]==1)
	{
		findcycle(x,last,x);
		long long left=k-now;
		left%=((long long)(c.size()));
		cout<<c[left];
		return ;
	}
	u[x]=1;
	go(a[x],now+1,x);
	u[x]=2;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(a[1]==1)
	{
		cout<<1;
		return 0;
	}
	go(1,0ll,-1);
	return 0;
}