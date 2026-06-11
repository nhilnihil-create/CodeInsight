#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  for(int i=0; i<S.size(); i++){
    if(S.at(i)!='x'){
      S.at(i)='x';
    }
  }
  cout<<S<<endl;
}