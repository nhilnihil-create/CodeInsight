#include<iostream>
#include<string.h>
using namespace std;
int main()
{
  string s,t;
  cin>>s;
  cin>>t;
  long a=s.length();
  int count=0;
  for(long i=0;i<a;i++)
  {
    if(s[i]!=t[i])
      count++;
  }
  cout<<count;
  return 0;
  
}
