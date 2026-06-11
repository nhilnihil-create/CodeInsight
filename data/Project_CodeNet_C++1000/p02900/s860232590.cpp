#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b;
  cin>>a>>b;
  long long c=gcd(a,b);
  long long factor=1;
  for(long long i=2;i<=sqrt(c);i++){
    if(c%i==0){
      factor++;
      while(c%i==0){
        c/=i;
      }
    }
  }
  if(c!=1) factor++;
  cout<<factor<<endl;
}