#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b;
 cin>>a>>b;
    a-=1;
    b-=1;
 if(b%a==0)
   cout<<b/a;
  else
    cout<<(b/a)+1;
  return 0;
}