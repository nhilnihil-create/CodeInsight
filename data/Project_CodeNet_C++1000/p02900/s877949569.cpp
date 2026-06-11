#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
long long gcd(long long a,long long b){
  if(b==0) return a;
  else return gcd(b,a%b);
}
int main(){
  long long A,B;
  cin>>A>>B;
  long long n=gcd(max(A,B),min(A,B));
  long long div=2;
  long long answer=1;
  while(div*div<=n){
    if(n%div==0){
      while(n%div==0) n=n/div;
      answer++;
    }
    div++;
  }
  if(n!=1) answer++;
  cout<<answer<<endl;
  
  return 0;
}