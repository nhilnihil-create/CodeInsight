#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int N;
  cin>>N>>S;
  for(int i=0; i<S.size(); i++){
    if(S.at(i)+N>90){
      S.at(i)=char(S.at(i)+N-90+64);
    }
    else{
      S.at(i)=char(S.at(i)+N);
    }
  }
  cout<<S<<endl;
}