#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  string s; cin >> s;

  s.erase(unique(s.begin(), s.end()), s.end());
  cout << s.size() << '\n';
}