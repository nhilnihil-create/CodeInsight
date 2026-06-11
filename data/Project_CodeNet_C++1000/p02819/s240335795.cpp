#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	long long int n,i,k,j,ans;
 	cin>>n;
 	if(n<=1)
 		ans=2;
 	else if(n==2)
 		ans=2;
 	else
 	{
	 
 	for(i=n;i<=pow(10,6);i++)
 		{
 			k=0;
 			for(j=2;j<=n/2;j++)
 				{
 					if(i%j==0)
					 	k++;	
				 }
			if(k==0)
			{
				ans=i;
				break;
			}
			
		 }
	}
		cout<<ans<<endl;
 }