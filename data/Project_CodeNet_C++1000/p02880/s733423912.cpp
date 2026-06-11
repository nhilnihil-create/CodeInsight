#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int Dmax= 9;
  int N;
  cin >> N;

  bool possible= false;
  for(int i=1; i<=Dmax; i++){
    for(int j=0; j<=Dmax; j++){
      if(i*j==N){
        possible= true;
        break;
      }
    }
    if(possible){ break; }
  }

  string ans= possible ? "Yes"
                       : "No";

  cout << ans << endl;
}