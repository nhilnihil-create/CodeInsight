#include<bits/stdc++.h>
using namespace std;
int k;queue<long long>q;
int main()
{
	cin>>k;
	for(int i=1;i<=9;++i)
	 q.push(i);
	while(--k)
	{
		long long x=q.front();q.pop();
		for(int i=max(0,(int)x%10-1);i<=min(9,(int)x%10+1);++i)
		 q.push(x*10+i);
	}
	cout<<q.front();
	return 0;
}