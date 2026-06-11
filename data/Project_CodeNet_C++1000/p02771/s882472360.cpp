#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,f=0;
  cin>>A>>B>>C;
  if(A==B && A!=C) f=1;
  if(A==C && A!=B) f=1;
  if(C==B && A!=C) f=1;
  
  if(f==1) cout<<"Yes";
  else cout<<"No";
  

}