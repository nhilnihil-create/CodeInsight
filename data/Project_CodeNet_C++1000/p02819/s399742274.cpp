#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
  int x,i,j,k,ans;
  cin>>x;
  if(x==1){cout<<"2"<<endl;return 0;}
  while(1)
  {
    i=2;
    while(1)
    {
      if(x%i==0&&x/i!=1){x++;break;}
      if(i*i>x){cout<<x<<endl;return 0;}
      i++;
    }
  }
}