#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,flag=0,count=0;
  cin>>n;
  string s;
  cin>>s;
  
  for(int i=0;i<n;i++)
  {
   if(s[i]=='A')
        flag=1;
    else if(s[i]=='B' && flag==1)
      flag=2;
     else if(s[i]=='C' && flag==2)
     {flag=0; count++;}
    else
      flag=0;
  }
  cout<<count<<endl;
 
  return 0;
}