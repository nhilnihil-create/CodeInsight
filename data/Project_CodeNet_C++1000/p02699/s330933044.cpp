#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int s,w;
  cin >> s >> w;
  
  if(s > w) cout << "safe" << endl;
  else cout << "unsafe" << endl;
  
}