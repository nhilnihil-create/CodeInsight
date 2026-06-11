#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	queue <long long> bfs;
	for (long long i=1;i<10;i++)
		bfs.push(i);
	while (!bfs.empty())
	{
		long long now=bfs.front();
		bfs.pop();
		a--;
		if (!a)
		{
			cout<<now<<endl;
			return 0;
		}
		if (now%10==9)
		{
			bfs.push(now*10+now%10-1);
			bfs.push(now*10+now%10);
		}
		else if (now%10==0)
		{
			
			bfs.push(now*10+now%10);
			bfs.push(now*10+now%10+1);
		}
		else
		{
			bfs.push(now*10+now%10-1);
			bfs.push(now*10+now%10);
			bfs.push(now*10+now%10+1);
		}
	}
	return 0;
}
