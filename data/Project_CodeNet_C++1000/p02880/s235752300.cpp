#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;cin>>N;
  bool can =false;
  for(int i=1;i<10;i++){
    if(N%i==0 && N/i<=9){
      can=true;
      break;
    }
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}