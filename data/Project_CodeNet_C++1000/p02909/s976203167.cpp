#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  vector<string> S = {"Sunny", "Cloudy", "Rainy"};
  rep(i, 3) {
    if(s == S[i]) {
      int sub = (i + 1) % 3;
      cout << S[sub] << endl;
    }
  }
  return 0;
}