#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t h;
  cin>> h;
  
  int64_t n=1,count=0;
  while(h>1){
    count+=n;
    h/=2;
    n*=2;
  }
  cout<< n+count << endl;
}