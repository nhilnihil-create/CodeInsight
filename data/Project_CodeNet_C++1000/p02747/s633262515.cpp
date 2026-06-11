#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  if(S.size()%2!=0){
    cout<<"No"<<endl;
    return 0;
  }
  for(int i=0;i*2<S.size();i+=2)
    if(S.at(i)!='h' || S.at(i+1)!='i'){
      cout<<"No"<<endl;
      return 0;
    }
  cout<<"Yes"<<endl;
}