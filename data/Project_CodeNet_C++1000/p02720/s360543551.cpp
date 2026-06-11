#include<bits/stdc++.h>
using namespace std;
	long long k=9,n;
struct node
{
	long long a,b;
};
	queue<node>Q;
int main()
{
	cin>>n;
	for(int i=1;i<=9;i++)
	{
		node tmp;
		tmp.a=tmp.b=i;
		Q.push(tmp);
	}
	while(!Q.empty())
	{
		node tmp=Q.front();
		Q.pop();
		long long a=tmp.a,b=tmp.b,t=tmp.a%10;
		if(b==n)
		{
			cout<<a;
			return 0;
		}
		for(int i=0;i<=9;i++)
		{
			if(abs(i-t)<=1)
			{
				node cur;
				cur.a=a*10+i;
				cur.b=++k;
				Q.push(cur);
			}
		}
	}
	return 0;
}