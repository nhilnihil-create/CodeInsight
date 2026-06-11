#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  cout<<(c%max(a,b)==0? c/max(a,b):c/max(a,b)+1)<<endl;
}