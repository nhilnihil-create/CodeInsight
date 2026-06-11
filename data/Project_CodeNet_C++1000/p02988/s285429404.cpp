#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,j,d,c=0;
 	cin>>n;
 	int a[n];
 	for(i=0;i<n;i++)
 		cin>>a[i];
 		for(i=1;i<n-1;i++)
 		{
 			if((a[i]>a[i-1]&&a[i]<a[i+1])||(a[i]<a[i-1]&&a[i]>a[i+1]))
 				c++;
		 }
 	cout<<c<<endl;	
 }