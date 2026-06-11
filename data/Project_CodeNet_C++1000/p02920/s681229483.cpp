#include <iostream>
#include <stdio.h>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int MN=20;
const int M=(1<<18)+5;
int n,m;
int s;
map<int,int,greater<int>> ma;

priority_queue<int> pq;
queue<int> qu;

int main()
{
	scanf("%d",&n);
	m=1<<n;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&s);
		ma[s]++;
	}
	pq.push(m);
	for(auto p:ma)
	{
		int cnt=p.second;
		if((int)pq.size()<cnt)
		{
			printf("No\n");
			return 0;
		}
		for(int i=0;i<cnt;i++)
		{
			qu.push(pq.top()); pq.pop();
		}
		while(!qu.empty())
		{
			for(int i=1;i<qu.front();i<<=1)
				pq.push(i);
			qu.pop();
		}
	}
	printf("Yes\n");
	return 0;
}