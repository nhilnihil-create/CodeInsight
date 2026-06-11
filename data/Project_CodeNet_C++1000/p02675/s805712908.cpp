#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  
  if(s[n-1] == '3') cout << "bon" << endl;
  else if(s[n-1] == '0' || s[n-1] == '1' || s[n-1] == '6' || s[n-1] == '8') cout << "pon" << endl;
  else cout << "hon" << endl;
}
