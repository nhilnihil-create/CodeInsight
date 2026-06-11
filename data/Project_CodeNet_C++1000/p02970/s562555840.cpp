#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n, d;
  cin >> n >> d;
  int sum = 2*d + 1;
  int cnt = 0;
  while(n > 0) {
    n -= sum;
    cnt++;
  }
  cout << cnt << endl;
}