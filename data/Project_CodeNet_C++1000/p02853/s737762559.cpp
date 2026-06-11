#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  c=0;
  cin>>a>>b;
  if(a==1)c+=300000;
  else if(a==2)c+=200000;
  else if(a==3)c+=100000;
  if(b==1)c+=300000;
  else if(b==2)c+=200000;
  else if(b==3)c+=100000;
  if(a==1&&b==1)c+=400000;
  cout<<c<<endl;
}