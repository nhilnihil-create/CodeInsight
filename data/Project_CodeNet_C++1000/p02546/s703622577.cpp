#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  
  int N;
  N = S.size();
  char last = S.at(N-1);
  if (last == 's') {
    cout << S + "es"<< endl;
  }
  else {
    cout << S + "s"<< endl;
  }
}