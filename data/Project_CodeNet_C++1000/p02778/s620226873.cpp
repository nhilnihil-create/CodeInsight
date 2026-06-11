#include <bits/stdc++.h>
using namespace std;

int main() {
  char s[101];
  cin >> s;
  for(int i = 0; s[i]; i++){
    s[i] = 'x';
  }
  cout << s << endl;  
}