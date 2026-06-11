#include <bits/stdc++.h>
using namespace std;

int check(int n){
  int cnt = 0;
  while (n) {
    n /= 10;
    cnt++;
  }
  if (cnt % 2 == 1) return 1;
  else
    return 0;
}

int main() {
    int n, out=0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      out += check(i);
    }
    cout << out << endl;
    return 0;
}
