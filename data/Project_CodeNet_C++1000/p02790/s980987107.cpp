#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int a,b,i,j;
 	string s,g;
 	cin>>a>>b;
 	for(i=0;i<a;i++)
 		s+=(char)(b+'0');
 	for(i=0;i<b;i++)
 		g+=(char)(a+'0');
 	if(a<=b)
 		cout<<g<<endl;
 	else
	 	cout<<s<<endl;	
 }