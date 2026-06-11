#include <iostream>
#include <vector>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, 0, n) cin >> v[i];
  int mx = 0, s = 0;
  rep(i, 1, n) {
    if(v[i] <= v[i-1]) {
      s++;
    } else {
      if(mx < s) mx = s;
      s = 0;
    }
  }
  if(mx < s) mx = s;
  cout << mx << "\n";
}