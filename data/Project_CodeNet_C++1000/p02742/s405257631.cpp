#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ll long long
using namespace std;

int main() {
  ll n, m;
  cin >> n >> m;
  if(n == 1 || m == 1) {
    cout << 1 << "\n";
    return 0;
  }
  cout << (n * m + 1) / 2 << "\n";
}
