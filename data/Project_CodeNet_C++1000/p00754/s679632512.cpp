#include "stdio.h"
#include "limits"
#include "algorithm"
#include "iostream"
#include "cmath"
#include "string"
#include "map"
#include "iomanip"
#include "stack"
using namespace std;

int main(){
  char S[110];
  bool FLAG;
  stack<char> temp;
  while(1){
    FLAG=true;
    gets(S);
    if(S[0]=='.')break;
    for(int i=0;S[i]!='.';++i){
      if(S[i]=='(' || S[i]=='[')temp.push(S[i]);
      if(S[i]==')'){
        if(temp.empty()){
          FLAG=false;
          break;
        }
        char a=temp.top();
        temp.pop();
        if(a!='('){
          FLAG=false;
          break;
        }

      }
      if(S[i]==']'){
        if(temp.empty()){
          FLAG=false;
          break;
        }
        char a=temp.top();
        temp.pop();
        if(a!='['){
          FLAG=false;
          break;
        }
      }
    }
    if(FLAG&&temp.empty())cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    while(!temp.empty())temp.pop();
  }
}