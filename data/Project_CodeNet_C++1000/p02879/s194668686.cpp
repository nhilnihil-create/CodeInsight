#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{

  int a,b;
  cin>>a>>b;
  if(a>9||b>9)cout<<"-1"<<endl;
  else cout<<a*b<<endl;
}