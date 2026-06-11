#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, d;
  	cin >> a >> b >> c >> d;
  	int x = (a + d - 1) / d;
  	int y = (c + b - 1) / b;
  	x >= y ? (cout << "Yes\n") : (cout << "No\n");
}
