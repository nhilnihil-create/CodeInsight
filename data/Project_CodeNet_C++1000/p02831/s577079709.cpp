#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int a,int b){
  if(a%b==0) return(b);
  else return(gcd(b,a%b));
}
  
  

int main() {
  int64_t A,B;
  cin>>A>>B;
  
  int64_t d=A*B;
  cout<<d/gcd(A,B)<<endl;
 
  
}
