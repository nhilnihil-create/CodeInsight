#include <bits/stdc++.h>
using namespace std;
int main(){
  string t;
  cin >> t;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == 'P') cout << "P";
    else cout << "D";
  }
  cout << endl;
  return 0;
}