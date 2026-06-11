#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int i,n,f=0;
 	string s,t;
 	cin>>n;
 	cin>>s;
 	if(n%2==0)
 	{
 		for(i=0;i<n/2;i++)
 			{
 				if(s[i]!=s[n/2+i])
 					{
 						f=1;
 						break;
					 }
			 }
	 }
	 else
	 	f=1;
	if(f==0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
 	
 }