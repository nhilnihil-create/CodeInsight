#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  char s[10010];
  cin >> n;
  cin >> s;
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    int x = s[i] -'A';
    x = (x + n) % 26;
    cout << char('A' + x);
  }
  cout << endl;
}