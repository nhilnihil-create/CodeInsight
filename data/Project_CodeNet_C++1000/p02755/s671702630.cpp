#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
  int i,j,k,a,b,ans;
  cin>>a>>b;
  i=0;
  while(1)
  {
    i++;
    if(i*8/100==a&&i*10/100==b){cout<<i;return 0;}
    if(i*8/100>a&&i*10/100>b){cout<<"-1";return 0;}
  }
  return 0;
}