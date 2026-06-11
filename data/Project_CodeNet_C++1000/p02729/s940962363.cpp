#include <bits/stdc++.h>
#define FOR(i, c) for (int i = 0; i < c; i++)
#define MOD 1000000007
using namespace std;

int cb(int n, int i) {
  int res = 1;
  for (int j = 0; j < i; j++) {
    res = res*(n-j)/(j+1);
  }
  return res;
}
int main() {
  int n , m;
  cin >> n >> m;
  cout << cb(m, 2) + cb(n, 2) << endl; 
  return 0;
}


