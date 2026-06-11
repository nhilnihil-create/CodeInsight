#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  bool a=false;
  for(int i=12;i<1000;i++){
    int C=i+1;
    int D=C*0.08,E=C*0.1;
    if(A==D && B==E){
      a=true;
      cout << C << endl;
      break;
    }
  }
  if(!a){
    cout << -1 << endl;
  }
}    