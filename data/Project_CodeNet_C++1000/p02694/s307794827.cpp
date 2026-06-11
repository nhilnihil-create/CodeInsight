#include <bits/stdc++.h>
using namespace std;

int main() {
  long long S=100, C=0;
  long long X;
  cin >> X;
  while ((S-X)<0) {
    S = S+S/100;
    C++;
  }
  cout << C << endl;
}