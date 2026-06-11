#include<bits/stdc++.h>
using namespace std;
 
int main(){
  long long a,b,aa=0,bb=0;
  cin>>a>>b;
  for(int i=1; i<=b; i++){
    aa=aa*10+a;
  }
  for(int i=1; i<=a; i++){
    bb=bb*10+b;
  }
  string A=to_string(aa);
  string B=to_string(bb);
  cout<<(A>=B?B:A)<<endl;
}