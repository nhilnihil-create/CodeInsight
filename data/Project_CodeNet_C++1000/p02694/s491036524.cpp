#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a=100;
  int64_t x;
  cin>>x;
  int count=0;
  while(a<x){
    a+=a/100;
    count++;
  }
  cout<<count<<endl;
}
