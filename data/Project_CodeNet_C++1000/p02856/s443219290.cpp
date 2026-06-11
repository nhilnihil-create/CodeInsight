#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long
using namespace std;
LL ans,sum,c,d;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d>>c;
		sum+=c*d;ans+=c; 
	}
	ans=ans-1+(sum-1)/9;
	cout<<ans;
	return 0;
}