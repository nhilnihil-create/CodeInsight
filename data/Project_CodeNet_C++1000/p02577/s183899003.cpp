#include<bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  int sum = 0;
  for(char c : s) {
    sum += (c - '0');
  }
  cout << (sum % 9 == 0 ? "Yes" : "No");
  return 0;
}