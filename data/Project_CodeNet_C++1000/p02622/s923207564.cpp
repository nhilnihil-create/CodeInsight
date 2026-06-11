#include<bits/stdc++.h>
using namespace std;
int main()
{
	string src;
	cin>>src;
	string dest;
	cin>>dest;
	int ch=0;
	  for(int i=0;i<src.length();i++)
	  {
		  if(src[i]!=dest[i])
			ch++;
		 
	  }
	  cout<<ch<<endl;
	  
}