#include <bits/stdc++.h>
using namespace std; 

int main() {
  int N;
  cin >> N;
  string s, t;
  cin >> s >> t;
  string u = "";
  for (int i = 0; i < N; i++) {
    u += (char)s[i];
    u+= (char)t[i];
  }
  cout << u << endl;
}
