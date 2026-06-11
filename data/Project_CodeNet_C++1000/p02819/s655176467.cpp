#include<bits/stdc++.h>
using namespace std;

bool isprime(int64_t n){
  for(int64_t i=2; i*i<=n; i++){
    if(n%i==0) return false;
  }
  return true;
}    

int main(){
  int64_t x;
  cin>> x;
  while(!isprime(x)){
    x++;
  }
  cout<<x<<endl;
}