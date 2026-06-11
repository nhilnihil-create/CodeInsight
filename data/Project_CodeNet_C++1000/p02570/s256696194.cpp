#include <bits/stdc++.h>
using namespace std;

int main(){
  int D, T, S;
  cin >> D >> T >> S;
  
  if (D%S == 0 && D/S <= T) cout << "Yes" << endl;
  else if(D%S!=0 && D/S < T) cout << "Yes" << endl;
  else cout << "No" << endl;
}