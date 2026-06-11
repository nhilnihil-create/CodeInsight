#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  if(a%c==0)cout<<b/c-a/c+1<<endl;
  else cout<<b/c-a/c<<endl;
}