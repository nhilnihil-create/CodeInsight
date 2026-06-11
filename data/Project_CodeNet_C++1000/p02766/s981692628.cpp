#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k,p;
  cin >>n>>k;
  while(n/k>0 ){
    n=n/k;
    p++;
  }
  cout <<p+1 <<endl;
}