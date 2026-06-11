#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	 long long int n,m,s=0,i,c=0;
 	 double p;
 	 cin>>n>>m;
 	 int a[n];
 	 for(i=0;i<n;i++)
 	 	cin>>a[i];
 	for(i=0;i<n;i++)
 		s=s+a[i];
 	p=(float)s/(float)(4*m);
 	for(i=0;i<n;i++)
 		{
 			if((float)a[i]>=p)
 				c++;
		 }
 //   cout<<p<<" "<<c<<endl;
	if(c>=m)	
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;  
 	return 0;
 }