#include<bits/stdc++.h>
using namespace std;

int main(){
  int X,N;
  cin >> X >> N;
  vector<int> P(N);
  for(int i=0;i<N;i++){
    cin >> P.at(i);
  }
  int i=0;
  while(true){
    int A=X-i,B=X+i;
    bool a=true,b=true;
    for(int i=0;i<N;i++){
      if(A==P.at(i)){
        a=false;
      }
    }
    if(a){
      cout << A << endl;
      return 0;
    }
    for(int i=0;i<N;i++){
      if(B==P.at(i)){
        b=false;
      }
    }
    if(b){
      cout << B << endl;
      return 0;
    }
    i++;
  }
}