#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,M;cin>>N>>M;
  vector<int> vec(M);
  for(int i=0;i<M;i++){
    cin>>vec[i];
  }
  
  int sum=0;
  for(int i=0;i<M;i++){
    sum+=vec[i];
  }
  
  if(sum<=N){
    cout<<N-sum<<endl;
  }
  else{
    cout<<"-1"<<endl;
  }
}