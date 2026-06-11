#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, n;
  long long k, l;
  cin >> a >> b >> n;
  if(n < b) {
    k = (a * n) / b;
    l = n / b;
    cout << k - a * l << endl;
  }
  else {
    k = (a * (b-1)) / b;
    l = (b-1) / b;
    cout << k -a * l << endl;
  }
}