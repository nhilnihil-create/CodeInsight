#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector<int>A(N);
  int sum=0;
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    sum+=A.at(i);
  }
  int count=0;
  for(int i=0;i<N;i++){
    int a=(sum+4*M-1)/(4*M);
    if(a<=A.at(i)){
      count++;
    }
  }
  if(count>=M){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}