#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin>>N;
  vector<int64_t> A(N);
  int64_t j=0;
  for(int64_t &i:A){
    cin>>i;
    j+=i;
  }
  int64_t k=0,l=2020202020;
  for(int64_t &i:A){
    k+=i;
    l=min(l,abs(j-k*2));
  }
  cout<<l<<endl;
}