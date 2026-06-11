#include <bits/stdc++.h>
using namespace std;

int main () {
  int count = 0;
  char prev = 'S';
  string S;
  cin >> S;
  for (int i = 0; i < (int)S.size(); i++) {
    char current = S.at(i);
    if (current == 'R') {
      if (prev == 'R') {
        count++;
      } else {
        count = 1;
      }
    }
    prev = current;
  }
  cout << count << endl;
}