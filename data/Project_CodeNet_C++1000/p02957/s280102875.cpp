#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ll A, B;
  cin >> A >> B;
  if ((A + B) % 2) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << (A+B) / 2 << endl;
  }
  
}