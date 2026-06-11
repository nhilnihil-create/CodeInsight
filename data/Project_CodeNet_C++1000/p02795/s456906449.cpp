#include<iostream>
using namespace std;
int main()
{
  int h,w,n,ma;
  cin>>h>>w>>n;
  ma=max(h,w);
  if(n%ma==0)
    cout<<n/ma<<endl;
  else
    cout<<(n/ma)+1<<endl;
  
  return 0;
}