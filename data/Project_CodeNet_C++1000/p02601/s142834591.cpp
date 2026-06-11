#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
    int k;
  cin >> a >> b >> c;
  cin >> k;
  while (k && b <= a) {
  	k--;
    b *= 2;
  }
  while (k && c <= b) {
   	k--;
    c *= 2;
  }
  if (b > a && c > b) printf("Yes");
  else printf("No");
	return 0;
}