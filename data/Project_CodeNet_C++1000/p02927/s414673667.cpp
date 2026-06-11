#include <bits/stdc++.h>
using namespace std;

int main() {
 long long M,D,X=0;
  cin >> M >> D;
  for(int i=1; i <= M; i++){
     for(int j=22; j <= D; j++){
       if(j%10 >= 2 && j/10 >= 2 && (j%10)*(j/10) == i){
         X++;
       }
     }
  }
  cout << X << endl;
}
