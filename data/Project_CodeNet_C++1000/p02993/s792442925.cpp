#include<bits/stdc++.h>
using namespace std;
int main(){
  string a;
  int X=0;
 cin>>a;
  for(int i=0;i<4;i++){
    if(a[i] == a[i+1]) {
      X++;
    }
  }
 if(X != 0) cout<<"Bad"<<endl;
 else cout<<"Good"<<endl;
  }
  