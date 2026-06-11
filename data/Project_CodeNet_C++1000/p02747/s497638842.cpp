#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  if(S.size()%2 !=0){
    cout<<"No"<<endl;
    return 0;
  }
  while(S.size()!=0){
    if(S.at(0)=='h' && S.at(1)=='i'){
      S=S.substr(2);
    }
    else{
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}
