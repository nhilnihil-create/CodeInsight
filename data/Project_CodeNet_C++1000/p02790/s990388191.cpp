#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >>a>>b;
  
  string s;
  if(a<b) {
    for(int i=0;i<b;i++) cout <<a;
    cout <<endl;
  }
  else if(a>b){
    for(int i=0;i<a;i++) cout <<b;
    cout <<endl;
  }
  else if(a==b){
    for(int i=0;i<a;i++) cout <<a;
    cout <<endl;
  }
  
}