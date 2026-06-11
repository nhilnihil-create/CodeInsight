#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  double p;
  cin>>p;
  double j;
  j=ceil(p/1000);
  j=j*1000;
  int k;
  k=j-p;
  cout<<k<<endl;
  return 0;
}