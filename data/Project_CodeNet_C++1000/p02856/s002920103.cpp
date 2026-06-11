#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
vector<int>G;
long long ans,sum;
int main()
{
	long long  m , d, c;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&d,&c);
		ans+=c;
		sum+=d*c;
	}
	long long dad=0;
	dad=ans-1+(sum-1)/9;
	cout<<dad;
	return 0;
}