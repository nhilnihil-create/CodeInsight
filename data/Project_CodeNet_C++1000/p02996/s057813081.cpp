#include<bits/stdc++.h>
using namespace std;

int main(){

  int N, i, a, b;
  map<int, int> data;
  cin>>N;
  
  for(i=0; i<N; i++){
    cin>>a>>b;
    data[b]+=a;
  }
  
  long long Sum=0;
  for(auto p : data){
    Sum+=p.second;
    if(Sum>p.first){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}