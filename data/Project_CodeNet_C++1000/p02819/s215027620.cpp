#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;cin>>X;
  vector<bool> prime(101000,true);
  vector<int> P;
  for(int i=2;i<101000;i++){
    if(!prime.at(i)) continue;
    P.push_back(i);
    if(i>=X){
      cout<<i<<endl;
      break;
    }
    for(int j=i;j<101000;j+=i) prime.at(j)=false;
  }
}