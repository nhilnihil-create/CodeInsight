#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,j,c=0;
 	string s;
 	cin>>s;
 	n=s.length();
 	i=0;
 	j=n-1;
 	while(i<j)
 	{
 		if(s[i++]!=s[j--])	
 		{
 			c++;
			
		 }
	 
 	}
 	cout<<c<<endl;
 }