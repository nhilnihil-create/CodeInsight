#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,m,i,s=0;
 	cin>>n>>m;
 	int a[m];
 	for(i=0;i<m;i++)
 		cin>>a[i];
 	for(i=0;i<m;i++)
 		s=s+a[i];
 	if(n>=s)
	 	cout<<n-s<<endl;
	else
		cout<<"-1"<<endl;
			
 	return 0;
 }