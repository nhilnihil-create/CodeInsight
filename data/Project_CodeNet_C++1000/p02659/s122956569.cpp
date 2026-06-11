#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;  

int main(void){
  long long  a,res;
  string tmp;
  int b;

  cin>>a;
  cin>>tmp;
  /*
  if(tmp[2]=='0' && tmp[3]=='0'){
    b=stoi(tmp.substr(0,1))*100;
  }
  else if(tmp[3]=='0'){
    b=stoi(tmp.erase(1,1))*10;
  }
  else{
    b=stoi(tmp.erase(1,1));
  }*/
  b=stoi(tmp.erase(1,1));
  //cout<<a<<" "<<b<<" "<<a*b<<endl;
  res=(a*b)/100;
  cout<<res;
  
  cout<<endl;
  return 0;
}