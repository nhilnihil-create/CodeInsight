#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
   
  int x,i,j,k;
  cin>>x;
  i=x/500;
  x=x-i*500;
  j=x/5;
  cout<<i*1000+j*5;
  
  return 0;
}