#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	long long sum1,sum2,sum3,sum4,sum;
	sum1=a*c;
	sum2=a*d;
	sum3=b*c;
	sum4=b*d;
	sum=max(max(sum1,sum2),max(sum3,sum4));
	cout<<sum<<endl;
	return 0;
}