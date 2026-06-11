/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0000
 */
#include<iostream>
#define B 9
using namespace std;
int main(){
  for(int i=0;i<B*B;cout<<(i/B+1)<<'x'<<(i%B+1)<<'='<<(i/B+1)*(i%B+1)<<endl,i++){}
  return 0;
}