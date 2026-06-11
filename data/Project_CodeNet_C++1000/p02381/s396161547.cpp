#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include<cctype>
#include<algorithm>
#include<string.h>
#include<iomanip>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148
using namespace std;
void deviation(double a[],double n);
double a[10000];
int sum=0;
double b[40];//??????????????°???
int main()
{
	double n;
    
	while(cin>>n)
	{
		memset(a,0,10000*sizeof(double));
		
		if(n==0)
			break;
		sum++;
		for(int i=0;i<n;i++)
			cin>>a[i];
		deviation(a,n);
		
	
	
	}
	




	for(int i=1;i<=sum;i++)
	{
		cout<<setiosflags(ios::fixed)<<setprecision(8);
	cout<<b[i]<<endl;
	}

}




	


	








void deviation(double a[],double n)
{
	double q=0,p;
	double i=0;
	for(int j=0;j<n;j++)
		
			q+=a[j];
	
	p=q/n;
	
		for(int j=0;j<n;j++)
		{
			double k=a[j]-p;//???????????????
			i=i+k*k;
		}
		
		b[sum]=sqrt(i/n);







}