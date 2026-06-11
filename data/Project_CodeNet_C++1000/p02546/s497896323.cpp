#include<bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  cout << S << (S[(int)S.size() - 1] == 's' ? "es" : "s") << endl;
}