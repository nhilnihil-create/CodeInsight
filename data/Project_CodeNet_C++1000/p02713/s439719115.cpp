#include <iostream>

using namespace std;
int gcd(int a, int b) {
  if (b > a) {
  	int tmp = a;
    a = b;
    b = tmp;
  }
  if (b == 0) return a;
  return gcd(b, a%b);
}
int main() {
	int k;
  	cin >> k;
  	int sum = 0;
  	int gcd1;
  	for (int i = 1; i <= k; i++) {
    	for (int j= 1; j <= k; j++) {
          	gcd1 = gcd(i, j);
        	for (int l = 1; l <= k; l++) {
              	sum += gcd(l, gcd1);
            }
        }
    }
  cout << sum;
  return 0;
}