#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  bool b=false;
  cin>>a;
  if(a.size()%2==0){
    for(int i=0;i<a.size();i+=2){
      if(a.at(i)!='h'){
        b=true;
        break;
      }
      if(a.at(i+1)!='i'){
        b=true;
        break;
      }
    }
  }
  else b=true;
  cout<<(b==true? "No":"Yes")<<endl;
}
