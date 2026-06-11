#include<bits/stdc++.h>
using namespace std;

int main(){
  int M, D;
  cin >> M >> D;
  int Ans=0;
  for(int i=1; i<=M; i++){
    for(int j=1; j<=D; j++){
      int D10=j/10;
      int D1=j-10*D10;
      if(D10>=2 && D1>=2 && D10*D1==i){
        Ans++;
      }
    }
  }
  cout << Ans << endl;
}