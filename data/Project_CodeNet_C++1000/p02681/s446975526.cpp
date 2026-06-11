#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

string S, T;

int main(){
  cin >> S >> T;
  string new_T = T.substr(0, S.size());
  if (S == new_T) cout << "Yes" << endl;
  else cout << "No" << endl;
}
