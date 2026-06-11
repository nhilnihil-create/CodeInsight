#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,D;
  cin>>A>>B>>C>>D;
  for(int i=0;i<100;i++){
    C-=B;
    if(C<=0){
      cout<<"Yes"<<endl;
      break;
    }
    A-=D;
    if(A<=0){
      cout<<"No"<<endl;
      break;
    }
  }
}