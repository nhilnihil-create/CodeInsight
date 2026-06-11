#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  string S; cin >> S;

  rep( i, 0, S.size() ) {
    if ( (i+1)%2 ) {
      if ( S[i]!='R' && S[i]!='U' && S[i]!='D' ) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if ( S[i]!='L' && S[i]!='U' && S[i]!='D' ) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
