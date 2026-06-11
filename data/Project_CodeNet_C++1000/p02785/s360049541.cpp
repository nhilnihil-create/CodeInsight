#include <bits/stdc++.h>
#define pi 3.14159
#include <map>
#include <iterator>
using namespace std;
int main()
 {
 	long long int n,k,i,j,f=0;
 	cin>>n>>k;
 	int a[n];
 	for(i=0;i<n;i++)
 		cin>>a[i];
 		sort(a,a+n);
 	if(k>=n)
 		f==0;
 	else
 		{
 			for(i=0;i<n-k;i++)
 				f+=a[i];
		 }
		cout<<f<<endl;
 	}