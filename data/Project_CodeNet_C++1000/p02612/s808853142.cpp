#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin >> n;
int x;
if (n%1000 == 0) {
  cout << 0;
} else {
x = 1000 - n%1000;
  cout << x;
}
	return 0;
}
