#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	long long sum1=0,sum2=0,sum3=0,sum4=0;
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	sum1=a*c;
	sum2=a*d;
	sum3=b*c;
	sum4=b*d;
	long long maxn=max(max(max(sum1,sum2),sum3),sum4);
	cout<<maxn<<endl;
	return 0;
}