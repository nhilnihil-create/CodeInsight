#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,j,d,c=0,k,s;
 	cin>>n>>d;
 	int a[n][d];
 	for(i=0;i<n;i++)
 		for(j=0;j<d;j++)
 			cin>>a[i][j];
 	for(i=0;i<n-1;i++)
 		{
 			
 			for(j=i+1;j<n;j++)
 			{
 				 s=0;
 				for(k=0;k<d;k++)
 					s=s+pow(a[i][k]-a[j][k],2);
			 
				int x=sqrt(s);
				if(x*x==s)
			 		c++;
			
			
		}
		 }
 		
 	
 	cout<<c<<endl;
 }