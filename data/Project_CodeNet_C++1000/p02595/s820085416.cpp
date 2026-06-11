#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

int main()
{
	int n,d;
	cin>>n>>d;
	int r=0;
	while(n--)
	{
		long long x,y;
		cin>>x>>y;
		double sum;
		sum=sqrt(x*x+y*y);
//		cout<<sum<<endl;
		if(sum<=d)
			r++;
	}
	cout<<r<<endl;
}