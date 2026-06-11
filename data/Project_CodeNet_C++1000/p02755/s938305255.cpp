#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin>>A>>B;
  bool flag=false;
  int X=0;
  while(!flag){
    if (X*8/100==A&&X*10/100==B){
      flag=true;
      break;
    }
    X++;
    if (X==1251){
      break;
    }
  }
  if (flag){
    cout<<X<<endl;
  }else{
    cout<<-1<<endl;
  }
}