#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int count=0;
  if(s.at(2)==s.at(3)){
    count++;
  }
  if(s.at(4)==s.at(5)){
    count++;
  }
  if(count==2){
    cout<<"Yes"<<endl;
  }
  else {
    cout<<"No"<<endl;
  }
}