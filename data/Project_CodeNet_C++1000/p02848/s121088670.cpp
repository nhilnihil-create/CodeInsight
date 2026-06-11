#include <bits/stdc++.h>
using namespace std;

int main() { 
  int N;
  string S;
  cin >> N >> S;
  int b;
  for (char c : S) {
    b = (c + N - 'A') % 26 +'A';
    cout << (char)b;
  }
  cout << endl;
} 