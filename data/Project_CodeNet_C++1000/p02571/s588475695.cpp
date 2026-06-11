#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  string S,T;
  cin >> S;
  cin >> T;
  
  int Ns = S.length();
  int Nt = T.length();

  int Smax = 0;
  int Smax_temp = 0;

  for (int i=0;i<Ns-Nt+1;i++){
    
    Smax_temp = 0;
    for (int j=0;j<Nt;j++){
      
      if(S[i+j]==T[j]){
        Smax_temp++;
      }
    }

    if(Smax < Smax_temp){
        Smax = Smax_temp;
    }
  }
  
  printf("%d\n", Nt-Smax);

  return 0;
}