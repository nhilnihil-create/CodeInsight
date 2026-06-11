#include<iostream>
using namespace std;
int main()
{
  int n,ans=0,now=0;
  cin>>n;
  do{
    now+=n;
    now%=360;
    ans++;
  }while(now%360!=0);
  cout<<ans;
}