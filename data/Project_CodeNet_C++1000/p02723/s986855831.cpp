#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  bool a=false;
  if(s.at(2)==s.at(3)&&s.at(4)==s.at(5)){
    a=true;
  }
  if(a){
    cout<<"Yes"<<endl;
  }
  else {
    cout<<"No"<<endl;
  }
}