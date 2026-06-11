#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  int a=1;
  for(int i=1;i<1000000000;i++){
    a*=k;
    if(a>n){
      cout<<i<<endl;
      break;
    }
  }
}