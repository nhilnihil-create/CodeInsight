#include <bits/stdc++.h>
using namespace std;
int main(){
  int N=0;
  cin>>N;
  vector <int> vec(N);
  for (int i=0; i<N; i++){
    cin>>vec.at(i);
  }
  int ans=0;
  int dans=100000000;
  int d=10000000;
  for(int i=0; i<100; i++){
    d=0;
    for(int j=0; j<N; j++){
      d+=(vec.at(j)-i)*(vec.at(j)-i);
    }
    if(d<dans){
      dans=d;
      ans=i;
    }
  }
  cout<<dans<<endl;
 
  
}