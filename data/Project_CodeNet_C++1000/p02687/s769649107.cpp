#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

char S[5];

int main(){
  rep(i, 3) cin >> S[i];
  if (S[1] == 'B') cout << "ARC" << endl;
  else cout << "ABC" << endl;
}
