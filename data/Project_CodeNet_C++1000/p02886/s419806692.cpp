#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	long long int n,i,m=0,j,s=0;
 	cin>>n;
 	int a[n];
 	for(i=0;i<n;i++)
 		cin>>a[i];
 	for(i=0;i<n-1;i++)
 		{
 			
 			for(j=i+1;j<n;j++)
 				{
 					m=m+a[i]*a[j];
				 }
				 
		 }
	cout<<m<<endl;
}