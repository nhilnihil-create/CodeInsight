#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  set<string> SE;
  while (cin >> S) SE.insert(S);
  cout << SE.size() << "\n"; 
}