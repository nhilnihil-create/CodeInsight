#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,count=1;
  string S;
  cin>>N>>S;
  for(int i=0; i<N-1; i++){
    if(S.at(i)==S.at(i+1)){
      continue;
    }
    else{
      count++;
    }
  }
  cout<<count<<endl;
}