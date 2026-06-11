#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin>>s>>t;
  int count=0;
  for(int i=0;i<s.size();i++){
    if(s.at(i)!=t.at(i)){
      count++;
      break;
    }
  }
  if(count==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}