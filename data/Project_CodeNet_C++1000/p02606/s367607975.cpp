#include<iostream>
using namespace std;
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  int x=c,ans=0;
  while(1)
  {
    if(c>b)
      break;
    if(c>=a && c<=b)
      ans++;
    c+=x;
  }
  cout<<ans<<endl;
}