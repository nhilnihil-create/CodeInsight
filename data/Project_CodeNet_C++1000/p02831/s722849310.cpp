#include<bits/stdc++.h>
using namespace std;

  unsigned long long gcd( unsigned long long a, unsigned long long b){
  if(a%b==0){
    return b;
  }else{
   return gcd(b,a%b);
  }
}

 int main(){
  unsigned long long A,B;
  cin>>A>>B;
 unsigned long long C=gcd(A,B);
 unsigned long long D=(A*B)/C;
  cout<<D<<endl;
}