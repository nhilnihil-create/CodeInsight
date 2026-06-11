#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long double A,B,C;
  cin>>A>>B>>C;
  long double a,b,c;
  a=sqrt(A)+0.00000000000001;
  b=sqrt(B)+0.00000000000001;
  c=sqrt(C)+0.00000000000001;
  if(a+b<c){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
