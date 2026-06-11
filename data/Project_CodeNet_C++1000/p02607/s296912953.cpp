#include<iostream>
using namespace std;
int main()
{
  int n,ans=0;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int a;
    cin>>a;
    if(i%2==0) continue;
    ans += a%2==1;
  }
  cout<<ans;
}