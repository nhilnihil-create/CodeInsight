#include <bits/stdc++.h>
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
    bool a=false,b=false;
    for(int j=0;j<N;j++){
      if(P.at(j)==A){
        a=true;
      }
      if(P.at(j)==B){
        b=true;
      }
    }
    if(!a){
      cout << A << endl;
      return 0;
    }
    if(!b){
      cout << B << endl;
      return 0;
    }
    i++;
  }
}
      