#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main(){
  string str,com,temp,s;
  int q,a,b,p;
  cin>>str>>q;
  for(int i=0;i<=q-1;i++){
    cin>>com>>a>>b;
    if(com=="print") {
      cout<<str.substr(a,b-a+1)<<endl;
    }
    else if(com=="reverse"){
      temp=str.substr(a,b-a+1);
      int n=temp.size();
      for(int i=0;i<=n-1;i++) {
        str[a+i]=temp[n-1-i];
      }
    }
    else if(com=="replace"){
      cin>>s;
      str=str.replace(a,b-a+1,s);
    }
  }
  return 0;
}