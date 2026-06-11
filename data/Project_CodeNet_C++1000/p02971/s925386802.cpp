#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin>>N;
  vector<int> vec(N);
  
  for(int x=0;x<N;x++){
    cin>>vec.at(x);
  }
  int one=0;
  for(int x=0;x<N;x++){
    if(vec.at(x)>=one) one=vec.at(x);
  }
  
  int two=0;
  for(int x=0;x<N;x++){
    if(vec.at(x)==one) continue;
    if(vec.at(x)>=two) two=vec.at(x);
  }
  int kai=0;
  for(int x=0;x<N;x++){
    if(vec.at(x)==one) kai++;
  }
  
  if(kai>=2){
    for(int x=0;x<N;x++){
    cout<<one<<endl;
    }
  }
    
  else{
    for(int x=0;x<N;x++){
      if(vec.at(x)!=one) cout<<one<<endl;
      else cout<<two<<endl;
    }
  } 
  
}