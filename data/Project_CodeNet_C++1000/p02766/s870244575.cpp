#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  int i=0;
  while(N>0){
    N=N/K;
    i++;
  }
  cout<<i<<endl;
}