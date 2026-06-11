#include<bits/stdc++.h>
using namespace std;
int k,num=9;queue<long long>q;
void bfs()
{
	while(!q.empty())
	{
		long long x=q.front(),lst=x%10;q.pop();
		for(int i=lst-1;i<=lst+1;++i)
		{
			if(i<0||i>9) continue;
			q.push(x*10+i);++num;
			if(num==k)
			{
				cout<<x*10+i;
				return;
			}
		}
	}
}
int main()
{
	cin>>k;
	for(int i=1;i<=9;++i)
	 q.push(i);
	if(k<=9) cout<<k;
	else bfs();
	return 0;
}