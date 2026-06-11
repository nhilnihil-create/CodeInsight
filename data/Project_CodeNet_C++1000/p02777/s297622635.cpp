#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s,t,u;
  int a,b;
  cin>>s>>t>>a>>b>>u;
  if(s==u) a--;
  if(t==u) b--;
  cout<<a<<" "<<b;
}