#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  int count = 0;
  string a, b = "";
  for (int i = 0; i < S.size(); i++) {
    a += S[i];
    if (a != b) {
      b = a;
      count++;
      a = "";
    }
  }
  cout << count << endl;
}
