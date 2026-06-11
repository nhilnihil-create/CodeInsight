#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int   X, Y;
  string S;
  cin >> X >> Y;
  
  if(Y % 2 == 0 && 2 * X <= Y && 4 * X >= Y) cout << "Yes" << endl;
  else cout << "No" << endl;
}
