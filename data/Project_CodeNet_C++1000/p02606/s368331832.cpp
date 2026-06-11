#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  t=1;
  while(t--){
  long long r,l,n,i,c=0;
  cin>>l>>r>>n;
  for(i=l;i<=r;i++)
  {
    if(i%n==0)
    {
      c++;
    }
  }
  cout<<c<<endl;
  }

}