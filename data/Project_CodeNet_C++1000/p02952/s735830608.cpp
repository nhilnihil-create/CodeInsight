#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int keta(int n) {
  string s = to_string(n);
  return s.size();
}
int main() {
  int n;
  cin >> n;
  int total = 0;
  for (int i = 1; i < n+1; i++) {
    int num = keta(i);
    if (num % 2 != 0) {
      total++;
    }
  }
  cout << total << endl;
}
