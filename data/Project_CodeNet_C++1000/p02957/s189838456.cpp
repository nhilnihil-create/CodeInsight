#include<iostream>
using namespace std;
int main()
{
int a,b;
  cin>>a>>b;
  if((b-a)&1)
    cout<<"IMPOSSIBLE";
  else
    cout<<((b-a)/2)+a;
}
