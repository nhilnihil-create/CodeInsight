#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,x; cin>>a>>b>>c;
  x=max(a,b); x=max(x,c);
  cout<<a+b+c-x<<endl;
}