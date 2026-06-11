#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  bool a=true;
  vector<int>vec(n);
  for (int i=0;i<n;i++){
    cin>>vec.at(i);
  }
  for (int i=0;i<n;i++){
    if(vec.at(i)%2==0&&vec.at(i)%3!=0&&vec.at(i)%5!=0){
      a=false;
      break;
    }
  }
  if(a){cout<<"APPROVED"<<endl;}
  else{cout<<"DENIED"<<endl;}
}