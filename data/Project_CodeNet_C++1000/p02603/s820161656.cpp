#include <bits/stdc++.h>
using namespace std;
int main()
{
 long int n,s=1000,t=0,q=0,r=1000,g=0,d=0;
	cin>>n;
   long long int arr[n+1];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	arr[n]=0;
	for(int i=0;i<n;i++)
	{
	    if(arr[i+1]>arr[i] &&q==0)
	    {
	     t=s/arr[i];
	    	s=s%arr[i];
	    	q++;
		}
	    else if(arr[i]==arr[i+1])
	    continue;
	    else{
	    	if(arr[i+1]<arr[i])
	    	{
	    s=s+t*arr[i];
	    t=0;
	    q=0;}
       	}
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i+1]>arr[i] &&d==0)
		{
			g=r/arr[i];r=r%arr[i];
			d++;
		}
		else if(arr[i]==arr[i+1])
	    continue;
	    else{
	    	r=r+g*arr[i];
	    	g=0;
	    	d=0;}
	    }
	cout<<max(r,s)<<endl;

	
}
