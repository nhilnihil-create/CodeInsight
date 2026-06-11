#include<iostream>
#include<string>
using namespace std;
int main(){
  string S,T;
  cin>>S;
  cin>>T;
  int count=0;
  for(int i=0;i<S.length();i++){
    if(S[i]!=T[i]){
      S[i]=T[i];
      count++;
    }
  }
  cout<<count;
  return 0;
}