#include <bits/stdc++.h>
using namespace std;
int main(){
string S;
  cin>>S;
  bool nazo=false;
 for(int i=0;i<S.size()-1;i++){
 	if(S.at(i)==S.at(i+1)){
    	nazo=true;
    }
 }
  if(nazo){
  cout<<"Bad";
  }
  else{
  cout<<"Good";
  }
}