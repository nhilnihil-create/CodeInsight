#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int n, S = 1;
  cin >> n;
  string s;
  cin >> s;
  char a = s[0];
  REP(i, n) {
    if(a != s[i]) {
      S++;
      a = s[i];
    }
  }
  cout << S << endl;
}