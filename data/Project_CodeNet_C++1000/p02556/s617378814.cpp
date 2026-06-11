#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n,x,y;
	int maxn=-1e11,maxx=1e11,minx=-1e11,minn=1e11;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x>>y,maxn=max(x+y,maxn),maxx=min(x+y,maxx),minx=max(x-y,minx),minn=min(x-y,minn);
	cout<<max(maxn-maxx,minx-minn)<<endl;	
	return 0;
}
