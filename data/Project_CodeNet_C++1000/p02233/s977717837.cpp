#include <iostream>
using namespace std;

typedef unsigned long long ull;
unsigned long long m[44]={0};


ull fib(int n) {
  if(m[n]!=0){
    return m[n];
  }
  if(n==0||n==1){
    m[n]=1;
    return 1;
  }else{
    m[n]=fib(n-1)+fib(n-2);
    return m[n];
  }
}

int main(void) {
  int n;
  cin >> n;
  cout << fib(n) << endl;
  return 0;
}