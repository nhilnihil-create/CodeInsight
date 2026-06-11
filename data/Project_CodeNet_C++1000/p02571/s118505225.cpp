#include<bits/stdc++.h>
using namespace std;
int main() {
  string S, T;
  int res = 0, loops, temp = 0;
  cin >> S >> T;
  if(S == T) {
    cout << 0 << endl;
    return 0;
  }
  res = T.size();
  loops = S.size() - T.size() + 1;
  for(int i = 0; i < loops; i++) {
    for(int j = 0; j < T.size(); j++) {
      if(S[i+j] != T[j]) temp++;
    }
    res = min(temp, res);
    temp = 0;
  }
  cout << res << endl;
}
    