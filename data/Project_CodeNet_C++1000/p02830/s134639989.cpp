#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int i,n;
 	string s,t,m;
 	cin>>n;
 	cin>>s>>t;
 	for(i=0;i<2*n;i++)
 	{
 		if(i%2==0)
 			m+=(char)(s[i/2]);
 		else
 			m+=(char)(t[i/2]);
 		
	 }
 	cout<<m<<endl;
 }