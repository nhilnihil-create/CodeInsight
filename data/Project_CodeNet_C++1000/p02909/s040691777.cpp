#include <bits/stdc++.h> 
using namespace std;

int main() {
  string S;
  cin >> S;
  string A = "Sunny",B = "Cloudy",C = "Rainy";
  if (S == A)
    cout << B << endl;
  if (S == B)
    cout << C << endl;
  if (S == C)
    cout << A << endl;
  
}
