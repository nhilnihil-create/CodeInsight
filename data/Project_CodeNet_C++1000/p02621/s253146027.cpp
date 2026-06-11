#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int a;
  int result=0;
  
  cin>>a;
  result=a*(1+a*(1+a));
  cout<<result<<endl;
  
  return 0;
  
}