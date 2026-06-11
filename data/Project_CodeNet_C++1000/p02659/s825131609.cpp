#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  long long int a,b,i;
  string s;
  cin>>a>>s;
  
  b=(s[0]-'0')*100+(s[2]-'0')*10+s[3]-'0';
  a=a*b/100;
  cout<<a<<endl;
  
}