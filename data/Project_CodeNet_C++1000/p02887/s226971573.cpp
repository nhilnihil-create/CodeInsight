#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int N;
string S;

int main(){
  cin >> N >> S;
  string::iterator itr = unique(S.begin(), S.end());
  S.erase(itr, S.end());
  cout << S.size() << endl;
}