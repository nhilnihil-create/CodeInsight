#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,ans=0;

map<int,bool> visited;
map<int,bool>::iterator it;

inline void get(int x)
{
	if (x==1)  return;
	
	int m=n;
	while (m%x==0)  m/=x;
	if (m%x==1) 
	{
		if (!visited[x])  visited[x]=1;
	}
}

signed main()
{
	cin>>n;
	for (int i=1;i*i<=n;i++)
	{
		if (n%i==0)  get(i),get(n/i);
	}
	for (int i=1;i*i<=n-1;i++)
	{
		if ((n-1)%i==0)  get(i),get((n-1)/i);
	}
	for (it=visited.begin();it!=visited.end();it++)  ans++;
	cout<<ans<<endl;
	
	return 0;
}