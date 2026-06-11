#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

bool blocked(char c) {
  return c == '#';
}

int main() {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;

  string S;
  cin >> S;

  rep(i,A,C-3) {
    if(S.substr(i,2)=="##"){
      cout << "No" << endl;
      return 0;
    }
  }

  for(int i=B; i < D-2; i++) {
    if (S.substr(i,2) == "##") {
      cout << "No" << endl;
      return 0;
    }
  }

  if (C < D) {
    cout << "Yes" << endl;
  } else {
    rep(i,B-2,D-2) {
      if (S.substr(i,3) == "...") {
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
  }

  return 0;
}
