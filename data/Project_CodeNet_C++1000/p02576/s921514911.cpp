#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  
  if(a%b==0)cout<<a/b*c<<endl;
  else cout<<a/b*c+c<<endl;
}
  
