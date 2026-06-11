#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  int x;
  char tui;
  string name;
  cin >> N;
  while(N>0){
    N--;
    x= N % 26;
    tui = x+97;
    name += tui;
    N /= 26;
  }
  reverse(name.begin(), name.end());
  cout << name << endl;
}