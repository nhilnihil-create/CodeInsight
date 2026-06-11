#include<iostream>
using namespace std;
int main()
{
  int n,x,k;cin>>n>>x>>k;
  if(n%x==0)
    cout<<(n*k)/x;
  else
    cout<<((n/x)+1)*k;
}
