#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int f[45];
int fib(int n){
  if(n==1||n==0)return 1;
  if(f[n]!=0)return f[n];
  else return f[n]=fib(n-1)+fib(n-2);
}
int main(){
  int  n;
  cin>>n;
  cout<<fib(n)<<endl;



  return 0;
}

