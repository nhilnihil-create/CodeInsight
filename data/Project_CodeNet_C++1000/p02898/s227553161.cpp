#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	long long int n,k,i,s=0;
 	cin>>n>>k;
 	int a[n];
 	for(i=0;i<n;i++)
 		cin>>a[i];
 	for(i=0;i<n;i++)
 		{
 			if(a[i]>=k)
 				s++;
		 }
 		
 	cout<<s<<endl;
 }