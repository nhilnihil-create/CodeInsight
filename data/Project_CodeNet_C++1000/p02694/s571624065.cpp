#include<bits/stdc++.h>
using namespace std;


int main(){
  long long x;
  cin>>x;
  long long p = 100, step = 0;

  while(p<x){
    p += p/100;
    step++;
  }
  cout<<step<<"\n";


  return 0;
}