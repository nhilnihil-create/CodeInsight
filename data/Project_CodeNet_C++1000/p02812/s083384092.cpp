#include<bits/stdc++.h>//B - Count ABC 
using namespace std;

int n,c;
string s;

int main()
{
	while(cin>>n>>s)
	{
	  c=0;
	  for(int i=0;i<n;i++)
	   {
		if(s[i]=='A')
		 if(s[i+1]=='B'&&s[i+2]=='C')
		   {
		     c++;
		     i+=2;
		   }
	    }
	   printf("%d\n",c);
	}
	return 0;
}