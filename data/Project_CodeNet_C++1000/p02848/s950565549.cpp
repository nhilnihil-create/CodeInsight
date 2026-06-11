#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  for(int i=0; i<s.size(); i++) {
    int p = s.at(i)-'A';
    p += n;
    p %= 26;
    char c = 'A'+p;
    cout << c;
  }
  cout << endl;
}