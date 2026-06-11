#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,f=0,g=0;
 	cin>>n;
 	int a[n];
 	for(i=0;i<n;i++)
 		cin>>a[i];
 	for(i=0;i<n;i++)
		 {
 			if(a[i]%2==0)
 				{
 					if(a[i]%3!=0)
 						{
 							if(a[i]%5!=0)
 								{
 									f=1;
 									break;
								 }
						 }	
 						
					 		
				 }
		 }
		 if(f==1)
		 	cout<<"DENIED"<<endl;
		else
			cout<<"APPROVED"<<endl;
 	return 0;
 }