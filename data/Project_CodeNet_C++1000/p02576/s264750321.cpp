#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int x;
  cin >> x;
  int t;
  cin >> t;
  int packet = n/x;
  if (n%x > 0) {
    packet = packet + 1;
  }
  cout << packet*t;
	return 0;
}
