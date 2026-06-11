#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,j,c=0,l;
 	string s;
 	cin>>n;
 	cin>>s;
 	l=s.length();
 	for(i=0;i<l;i++)
 	{	
 		if(s[i]+n<=90)
 			s[i]=s[i]+n;
 		else
 			s[i]=(char)(65+(n-90+s[i]-1));
 			
	 }
	 cout<<s<<endl;
}