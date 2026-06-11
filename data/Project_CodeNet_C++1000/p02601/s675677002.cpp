#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;cin>>A>>B>>C;
  int K;cin>>K;
  bool can=false;
  for(int i=0;i<=K;i++){
    for(int j=0;j<=K-i;j++){
      int Bi=B*pow(2,i);
      int Cj=C*pow(2,j);
      if(A<Bi && Bi<Cj){
        can =true;
        break;
      }
    }
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}