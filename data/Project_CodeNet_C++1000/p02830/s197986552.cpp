#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  rep(i, 0, n) {
    cout << s[i] << t[i];
  }
  cout << "\n";
}
