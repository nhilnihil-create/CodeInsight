#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,x,d,c=1,s=0;
 	cin>>n>>x;
 	int a[n],b[n];
 	for(i=0;i<n;i++)
 		cin>>a[i];
 	for(i=0;i<n;i++)
 		{
 			s=s+a[i];
 			if(s<=x)
 				c++;
		 }
		 cout<<c<<endl;
 }