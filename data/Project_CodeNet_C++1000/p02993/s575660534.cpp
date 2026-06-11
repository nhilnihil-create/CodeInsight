#include<bits/stdc++.h>
using namespace std;
int main(){
  string n;
  cin>>n;
  for(int i=1;i<=3;i++){
    if(n[i]==n[i-1]){
      cout<<"Bad\n";
      return 0;
    }
  }
  cout<<"Good\n";
  return 0;
}