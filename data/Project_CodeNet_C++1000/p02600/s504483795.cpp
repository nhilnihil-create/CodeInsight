#include<iostream>
using namespace std;
int main()
{
  int x;
  cin>>x;
  if(x>399 && x<600)
    cout<<8<<endl;
  else if(x>599 && x<800)
    cout<<7<<endl;
  else if(x>799 && x<1000)
    cout<<6<<endl;
  else if(x>999 && x<1200)
    cout<<5<<endl;
  else if(x>1199 && x<1400)
    cout<<4<<endl;
  else if(x>1399 && x<1600)
    cout<<3<<endl;
  else if(x>1599 && x<1800)
    cout<<2<<endl;
  else if(x>1799 && x<2000)
    cout<<1<<endl;
  return 0;
}