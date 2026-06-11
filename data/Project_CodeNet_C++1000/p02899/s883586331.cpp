#include<iostream>
using namespace std;
int main()
{
    long  int n,*a,i,j,temp,*index,temp_index;
    cin>>n;
    a=new long int[n];
    index=new long int[n];
    for(i=0;i<n;i++)
    {
	    cin>>a[i];
	    index[i]=i;
    }  
    for(i=1;i<n;i++)
    {
        j=i-1;
	temp=a[j+1];
	temp_index=index[j+1];
	while(j>=0&&a[j]>temp)
	{
		a[j+1]=a[j];
		index[j+1]=index[j];
		j--;
	}
	a[j+1]=temp;
	index[j+1]=temp_index;
    }

    for(i=0;i<n;i++)
	    cout<<index[i]+1<<" ";
    
}
