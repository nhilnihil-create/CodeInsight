#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  string str;
  int n,pos;
  while(1){
    cin>>str;
    if(str=="-") break;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>pos;
      str = str + str;
      str = str.substr(pos,str.length()/2);
    }
    cout<<str<<endl;
  }
  return 0;
}