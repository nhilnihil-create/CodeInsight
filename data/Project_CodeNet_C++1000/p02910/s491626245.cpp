#include <bits/stdc++.h>
using namespace std;
int main(){
string S;
  cin>>S;
  bool nazo=true;
  for(int i=0;i<S.size();i++){
  	if(i%2==0){
    	if(S.at(i)== 'R' || S.at(i)=='U' || S.at(i)=='D' ){
        continue;
        }
      	else{
        nazo=false;
        }
    }
    else{
    if(S.at(i)== 'L' || S.at(i)=='U' || S.at(i)=='D' ){
        continue;
        }
      	else{
        nazo=false;
        }
      
    }
  }
  
  
  
  if(nazo){
  cout<<"Yes"<<endl;
  }
  else{
  cout<<"No"<<endl;
  }
}
