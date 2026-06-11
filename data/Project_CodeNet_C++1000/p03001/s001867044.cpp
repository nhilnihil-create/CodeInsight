#include <bits/stdc++.h>
using namespace std;
int main(){
  int64_t W,H,x,y,A=0;
  cin>>W>>H>>x>>y;
  string S="";
  if(W==x*2&&H==y*2){
    A=1;
  }
  if((W*H)%2){
    S=".5";
  }
  cout<<(W*H)/2<<S<<" "<<A<<endl;
}