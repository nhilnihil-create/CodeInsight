#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
long long n,a[202020],b[202020],ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]<a[i])
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	priority_queue<pair<long long,long long> >pq;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			pq.push(make_pair(b[i],i));
		}
	}
	while(!pq.empty())
	{
		long long x=pq.top().first,y=pq.top().second;
		pq.pop();
		long long sum=b[(y+n-1)%n]+b[(y+1)%n];
		if(b[y]-a[y]<sum)
		{
			cout<<-1<<endl;
			return 0;
		}
		long long cnt=(b[y]-a[y])/sum;
		b[y]-=sum*cnt;
		ans+=cnt;
		if(b[y]<=a[y])
		{
			continue;
		}
		pq.push(make_pair(b[y],y));
	}
	cout<<ans<<endl;
	return 0;
}