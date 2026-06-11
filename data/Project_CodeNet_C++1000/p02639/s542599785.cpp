#include<bits/stdc++.h>

using namespace std;

int main()
{
  int x=5;
  long long int n,ans=0;
  while(x--)
  {
    cin>>n;
    if(n==0)ans=5-x;
  }
  cout<<ans<<endl;
}