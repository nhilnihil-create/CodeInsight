#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,K;
  cin >>A>>B>>C>>K;
  int i=0,j=0;
  while(A>0&&K>0){
    A--;
    K--;
    i++;
  }
  while(B>0&&K>0){
    B--;
    K--;
  }
  while(C>0&&K>0){
    C--;
    K--;
    j++;
  }
  cout<<i-j<<endl;
}
