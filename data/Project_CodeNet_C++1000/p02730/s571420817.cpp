#include <bits/stdc++.h>
using namespace std;

int main()
 {
 	string s;
 	cin>>s;
 	int i,n,f=0,g=0;
 	n=s.length();
 	for(i=0;i<n;i++)
 		{
 			if(s[i]!=s[n-i-1])
 				f=1;
		 }
	for(i=0;i<(n-1)/2;i++)
		{
			if(s[i]!=s[(n-1)/2-i-1])
				g=1;
		}
	if(f==0&&g==0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
 	return 0;
 }
