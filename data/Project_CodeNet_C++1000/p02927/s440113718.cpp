#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int M,D;
  int S=0;
  cin>>M>>D;
  for(int X=1;X<=M;X++){
    for(int Y=22;Y<=D;Y++){
      if((Y/10)*(Y%10)==X&&Y%10>1){
        S++;
      }
    }
  }
  cout<<S<<endl;
}
