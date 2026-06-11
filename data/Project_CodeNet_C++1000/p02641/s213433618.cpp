#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  int N;
  cin >> N;
  vector<int> P(N);
  for(int i=0;i<N;i++){
    cin >> P.at(i);
  }
  int A,B;
  int i=X;
  while(true){
    bool a=false;
    for(int j=0;j<N;j++){
      if(i==P.at(j)){
        a=true;
        break;
      }
    }
    if(!a){
      A=i;
      break;
    }
    i--;
  }
  i=X;
  while(true){
    bool b=false;
    for(int j=0;j<N;j++){
      if(i==P.at(j)){
        b=true;
        break;
      }
    }
    if(!b){
      B=i;
      break;
    }
    i++;
  }
  if(abs(A-X)<=abs(B-X)){
    cout << A << endl;
  }
  else{
    cout << B << endl;
  }
}