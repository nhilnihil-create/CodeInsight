#include <iostream>
#include <algorithm>
#define MAX_N 123456 * 2
using namespace std;

bool t[MAX_N];
int n;

bool isPrime(int x) {
  if(x == 2) return true;
  if(x < 2 || x % 2 == 0) return false;
  int i = 3;
  while(i * i <= x) {
    if(x % i == 0) return false;
    i += 2;
  }
  return true;
}

void table() {
  for(int i = 0; i < MAX_N; ++i) {
    if (isPrime(i)) t[i] = 1;
  }
}

void solve() {
  int sum = 0;
  for(int i = n + 1; i <= n * 2; ++i) {
    if(t[i]) sum++;
  }
  cout << sum << endl;
}

int main() {
  table();
  while(cin >> n && n) {
    solve();
  }
  return 0;
}

