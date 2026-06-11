#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int a,b,c,d,f=0;
 	cin>>a>>b>>c>>d;
 	while (a>0&&c>0)
 	{
 		c=c-b;
 		if(a>0&&c>0)
 			a=a-d;
	 }
	 if(a<=0)
	 	cout<<"No"<<endl;
	else 
		cout<<"Yes"<<endl;
 	return 0;
 }