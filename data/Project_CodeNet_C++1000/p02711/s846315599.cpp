#include <bits/stdc++.h>
using namespace std;

int main(){
  string N;
  cin>>N;
  bool ans=true;
  for(int i=0;i<3;i++){
    if(N.at(i)=='7'){
      cout<<"Yes"<<endl;
      ans=false;
      break;
    }
  }
  if(ans){
    cout<<"No"<<endl;
  }
}