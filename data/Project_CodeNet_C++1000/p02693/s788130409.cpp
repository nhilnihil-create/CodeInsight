#include<iostream>
using namespace std;
int main (void)
{
 int a,b,k,i,s;
  cin>>k>>a>>b;
  i=0;
  while(1)
  {
    i++;
    s=k*i;
   if(s>b){cout<<"NG";break;}
   else if(s>=a){cout<<"OK";break;}
  }
}
