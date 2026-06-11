#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int a,b,n,t,k,k1;
  cin>>a>>b>>n;
  if(b>n)
  {
      cout<<(a*n)/b;
  }
  else
  {
       cout<<(a*(b-1))/b;
  }

}
