#include<bits/stdc++.h>
using namespace std;
int main(){
  string S,T;
  cin>>S>>T;
  int a=0;
  for(int i=0;i<S.size();i++){
    if(S.at(i)!=T.at(i)){
      S.at(i)=T.at(i);
      a++;
    }
  }
  cout<<a<<endl;
}