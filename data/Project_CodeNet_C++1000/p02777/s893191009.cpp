#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,T,U;
  int A,B;
  cin>>S>>T;
  cin>>A>>B;
  cin>>U;
  
  if(S==U) A--;
  else B--;
  cout<<A<<" "<<B<<endl;
}