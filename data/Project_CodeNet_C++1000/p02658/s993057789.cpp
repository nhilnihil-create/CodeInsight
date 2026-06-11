#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n;
  cin>>n;
  int64_t x=1;
  bool a=false;
  bool b=false;
  vector<int64_t>vec(n);
  for(int i=0;i<n;i++){
    cin>>vec.at(i);
    if(vec.at(i)==0){
      a=true;
      break;
    }
  }
  
  for(int i=0;i<n;i++){
    if(vec.at(i)<=1000000000000000000/x){
      x*=vec.at(i);
      
    }
    else {b=true;
         break;
         }
  }
  if(a){
    cout<<"0"<<endl;}
  else if(b){
    cout<<"-1"<<endl;}
  else{cout<<x<<endl;}
}
