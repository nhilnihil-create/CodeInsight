#include<iostream>
using namespace std;
int main()
{
  int t;
  cin>>t;
  if(t<600)
    cout<<"8";
  else if(t>=600&&t<800)
    cout<<"7";
  else if(t>=800&&t<1000)
    cout<<"6";
  else if(t>=1000&&t<1200)
    cout<<"5";
  else if(t>=1200&&t<1400)
    cout<<"4";
  else if(t>=1400&&t<1600)
    cout<<"3";
  else if(t>=1600&&t<1800)
    cout<<"2";
  else
    cout<<"1";
  return 0;
}