#include<bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c=1,x; cin>>a>>b,x=a;
  if(b==1) c=0;
  else while(x<b) c++,x+=a-1;
  cout<<c;
}