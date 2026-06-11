#include<bits/stdc++.h>

using namespace std;
int main()
{
  int a,b,p,q;
  cin>>a>>b;
  p=max(a,b);
  q=min(a,b);
  for(int i=0;i<p;i++) cout<<q;
  return 0;
}