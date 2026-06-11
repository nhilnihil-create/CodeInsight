#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin>>N>>S;
  bool ans=true;
  if(N==1){
    cout<<"No"<<endl;
    ans=false;
  }
  for(int i=0;i<N/2;i++){
    if(N%2!=0){
      cout<<"No"<<endl;
      ans =false;
      break;
    }else if(S.at(i)!=S.at(N/2+i)){
      cout<<"No"<<endl;
      ans =false;
      break;
    }
  }
  if(ans){
    cout<<"Yes"<<endl;
  }
}