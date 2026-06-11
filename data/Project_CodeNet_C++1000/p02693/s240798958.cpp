#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;
  cin>>N>>A>>B;
  bool ans =true;
  for(int i=A;i<=B;i++){
    if(i%N==0){
      ans=false;
      cout<<"OK"<<endl;
      break;
    }
  }
  if(ans){
    cout<<"NG"<<endl;
  }
}