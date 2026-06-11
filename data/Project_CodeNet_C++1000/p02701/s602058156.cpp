#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i = 0; i < n; i++) cin >> s.at(i);
  sort(s.begin(), s.end());
  int c = 0;
  string get;
  for(int i = 0; i < n; i++) {
    if(s.at(i) != get) {
      c++;
      get = s.at(i);
    }
  }
  cout << c << endl;
}