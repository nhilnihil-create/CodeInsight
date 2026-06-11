#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long x,y=100;cin>>x;
  int cnt=0;
  while(y<x) y+=y/100, ++cnt;
  cout<<cnt<<endl;
  return 0;
}
