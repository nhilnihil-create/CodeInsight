#include <bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
  long long int a,b,i;
  cin>>a>>b;
  long long int big=max(a,b);
  long long int small=min(a,b);
  for(i=big;;i=i+big)
  {
      if(i%small==0)
      {
          cout<<i;
          break;
      }
  }

   return 0;
}
