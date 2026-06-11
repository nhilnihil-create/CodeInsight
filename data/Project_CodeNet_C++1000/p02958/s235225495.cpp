#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,d,c=0;
 	cin>>n;
 	int a[n],b[n];
 	for(i=0;i<n;i++)
 		cin>>a[i];
 	for(i=0;i<n;i++)
 		b[i]=a[i];
 	sort(a,a+n);
 	for(i=0;i<n;i++)
 		{
 			if(a[i]!=b[i])
 				c++;
		 }
	if(c<=2)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
 	
}