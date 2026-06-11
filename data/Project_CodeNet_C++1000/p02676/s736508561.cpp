#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int k ;cin>>k;
  string s ;	cin>>s;
  	int n = s.length();
  	if(n <=k )
      cout<<s<<endl;
  	else 
     {   for(int i = 0 ; i < k ;i++)cout<<s[i]; cout<<"..."<<endl;   } 
  




}