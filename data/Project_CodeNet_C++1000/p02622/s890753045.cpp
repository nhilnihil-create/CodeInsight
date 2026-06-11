#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  string str,str1;
  int n,c,i;
  cin>>str>>str1;
  n=str.length();
  c=0;
  for(i=0;i<n;i++)
  {
    if(str[i]!=str1[i])
      c++;
  }
  cout<<c<<endl;
  return 0;
}