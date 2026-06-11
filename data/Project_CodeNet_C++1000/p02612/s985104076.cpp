#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 0;
  cin >> n;
  int m = n % 1000;
  if (m == 0){
    cout << 0;
    return 0;
  }
  int v = 1000 - m;
  cout << v;
	return 0;
}
