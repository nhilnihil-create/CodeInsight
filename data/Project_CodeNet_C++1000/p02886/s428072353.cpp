#include <iostream>
#include <vector>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  int sum = 0;
  rep(i, 0, n) cin >> v[i];
  rep(i, 0, n) {
    rep(j, 0, n) {
      if(i == j) continue;
      sum += v[i]*v[j];
    }
  }
  cout << sum / 2 << "\n";
}