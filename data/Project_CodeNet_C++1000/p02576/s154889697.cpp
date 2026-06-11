#include <iostream>
using namespace std;
int main()
{
  int n,x,t,count;
  cin>>n>>x>>t;
  if(n%x>0)
  {count=(n/x+1)*t;}
  else{count=(n/x)*t;}
  cout<<count;
  return 0;
}