#include<iostream>
using namespace std;
int main()
{
        long long int i,j,temp,n,*a;
	cin>>n;
	a = new long long int[n];
        for(i=0;i<n;i++)
		cin>>a[i];

	for(i=1;i<n;i++)
        {
           j=i-1;
	   temp=a[i];
	   while(j>=0&&a[j]>temp)
	   {
		   a[j+1]=a[j];
		   j--;
	   }
	   a[j+1]=temp;
        }

	if(n&1)cout<<0;
	else
	{
           int index;
	   index = n/2-1;
	   cout<<a[index+1]-a[index];
	}


	
}
