#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int k = s.size();
  for(int i = 0;i < k;i++) {
    if('A' <= (char)(s[i] + n) && (char)(s[i] + n) <= 'Z') 
      cout << (char)(s[i] + n);
    else cout << (char)(s[i] + n - 26);
  }
}