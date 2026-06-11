#include<iostream>
using namespace std;
#define size 1000
int main()
{
	int n,i,j;
	float v[size],number;
	double sum;
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>v[i];
    }
    for(i=0;i<n-1;i++)
    {
       j=i+1;
       number = v[j];
       while(number<v[j-1] && j>0)
       {
       	 v[j] = v[j-1];
       	 j--;
       }
       v[j]=number;
    }
    sum = v[0];
    for(i=1;i<n;i++)
    {
    	sum=(sum+v[i])/2.0;
    }
    cout<<sum;

}