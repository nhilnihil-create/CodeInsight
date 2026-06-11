#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, X, T; cin >> N >> X >> T;
  
  int last =0;
  if(N%X > 0) last++;
  
  cout << ((N/X)*T + T*last) << endl;
  return 0;
}
