#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
  int a,b,c,d,K;
  cin >>a>>b>>c>>d>>K;
  int M = c-a;
  int N = d-b;
  int i;
  if(N>=0){
  i = 60*M + N;
  }
  else if(N<0){
  i = 60*M + N; 
  }
  if(i-K>=0){
  cout << i-K << endl;
  }
  else if(i-K<0){
  cout << "0" << endl;
  }
}