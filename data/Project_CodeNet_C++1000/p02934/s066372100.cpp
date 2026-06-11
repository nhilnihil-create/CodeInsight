#include<iostream>
using namespace std;
int main()
{
	int n;
	float sum=0.0,sum1=0.0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=0;i<n;i++)
	{
	
	sum=sum+((float)1/a[i]);
}

	 sum1=1/sum;
	cout<<sum1<<endl;
	

}