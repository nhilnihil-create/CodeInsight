#include <iostream>
#include<cstring>
using namespace std;
int main()
{
  int a,b;
  string s,t,u;
  cin>>s>>t;
  cin>>a>>b;
  cin>>u;
  if(s[0]==u[0])
    a=a-1;
  else if(t[0]==u[0])
    b=b-1;
cout<<a<<" "<<b;
   return 0;
}
