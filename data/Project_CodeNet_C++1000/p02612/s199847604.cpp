#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>> N;
  while(N>1000){
    N=N-1000;
  }
    cout<<1000-N;
}