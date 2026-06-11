#include<iostream>
using namespace std;

int main() {
  string S; cin >> S;
  if (S.back() == 's') S += "es";
  else S += "s";
  cout << S << endl;
}