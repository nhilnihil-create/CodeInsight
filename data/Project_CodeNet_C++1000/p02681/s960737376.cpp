#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  int cnt = 0;
  cin >> S;
  cin >> T;
  int size = S.size();
  for (int i = 0; i < size; i++) {
    if (S.at(i)!=T.at(i)) break;
    else cnt++;
  }
  if (cnt==size) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
