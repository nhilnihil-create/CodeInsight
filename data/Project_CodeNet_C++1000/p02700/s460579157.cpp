#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d; cin>>a>>b>>c>>d;
  bool T_win=true,A_win=true;
  while(T_win||A_win){
    c-=b;
    if(c<=0){
      A_win=false;
      break;
    }
    a-=d;
    if(a<=0){
      T_win=false;
      break;
    }
  }
  if(T_win)
    cout<<"Yes"<<endl;
  if(A_win)
    cout<<"No"<<endl;
}