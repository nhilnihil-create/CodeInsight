#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,k=0;
  cin>>N>>K;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    if(j>=K)
      k++;
  }
  cout<<k<<endl;
}