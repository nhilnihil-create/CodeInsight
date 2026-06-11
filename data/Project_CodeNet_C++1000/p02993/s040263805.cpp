#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
  string S; cin >> S;
  if (S[0] != S[1] && S[1] != S[2] && S[2] != S[3])
    cout << "Good" << endl;
  else
    cout << "Bad" << endl;
}