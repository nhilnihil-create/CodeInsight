#include<iostream>
using namespace std;
int main()
{
  int a[5],t;
  for(int i =0;i<5;++i)
  {
    cin>>a[i];
    if(a[i]==0)  t=i+1;   
  }
  cout<<t;
  
}