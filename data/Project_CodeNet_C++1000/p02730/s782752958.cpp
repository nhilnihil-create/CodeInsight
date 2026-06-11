#include<bits/stdc++.h>
using namespace std;

int main(){
  string S,T,U,V;
  cin>>S;
  
  int N;
  N=S.size();
  
  for(int i=0;i<N;i++){
    T+=S.at(N-i-1);
  }
  for(int i=0;i<(N-1)/2;i++){
    U+=S.at(i);
  }
  for(int i=0;i<(N-1)/2;i++){
    V+=U.at((N-1)/2-i-1);
  }
  
  if(S==T&&U==V){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
  
  
