#include<iostream>
using namespace std;
int main (void)
{
  long long int x,a=100;
  int i=0;
  cin>>x;
  while(a<x){a=a+a/100;i++;}
  
  cout<<i;

}