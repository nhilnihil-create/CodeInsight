#include<bits/stdc++.h>
using namespace std;

int n;

struct az
{
	int a;
	int b;
}q[200005];

bool cmp(az x , az y)
{
	return x.b < y.b;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	   scanf("%d%d",&q[i].a,&q[i].b);
	long long now=0;
	sort(q+1,q+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		now+=q[i].a;
		if(now > q[i].b ) 
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}