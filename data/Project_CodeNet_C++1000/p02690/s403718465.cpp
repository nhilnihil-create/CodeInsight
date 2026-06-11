#include<iostream>
#include<cmath>
#include<string>
using namespace std;


int main()
{
  int X,X_02,tmp;
  bool flag=false;
  
  cin>>X;
  X_02=pow((double)X,1.0/5.0)*2;
  for(int i=0;i<X_02;i++)
  {
    for(int j=0;j<X_02;j++)
    {
      tmp=i*i*i*i*i-j*j*j*j*j;
      if(tmp==X)
      {
        cout<<i<<" "<<j;
        flag=true;
        break;
      }
      
      tmp=i*i*i*i*i+j*j*j*j*j;
      if(tmp==X)
      {
        cout<<i<<" "<<(-1)*j;
        flag=true;
        break;
      }
    }
    if(flag)
      break;
  }
}