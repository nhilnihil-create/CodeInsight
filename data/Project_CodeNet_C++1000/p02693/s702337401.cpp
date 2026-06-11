#include<iostream>
using namespace std;
int main()
{
  int k,a,b;
  cin>>k>>a>>b;
  int flag=0;
  for(int i=a;i<=b;i++)
  {
    if(i%k==0)
    {
      flag=1;
      break;
    }
  }
  if(flag==1)
  {
    cout<<"OK"<<endl;
  }
    else
    {
      cout<<"NG"<<endl;
    }
  return 0;
  }
