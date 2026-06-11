#include <iostream>

using namespace std;

const int p = 1000000007;

int inv(int a) {
  // Calculates a ^ p-2 mod p
  int n = p - 2;
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans = (ans * a) % p;
    a = ((long long)a * a) % p;
    n >>= 1;
  }
  return (int)ans;
}

int solve(int X, int Y) {
  if ((X + Y) % 3 != 0) return 0;

  int N = (X + Y) / 3;
  int R1 = (2 * X - Y) / 3;
  int R2 = (2 * Y - X) / 3;
  if (R1 < R2) swap(R1, R2);

  if (R1 < 0 || R2 < 0) return 0;

  // For valid coordinates, we want to determine (X+Y)/3 C (2X-Y)/3
  int numerator = 1;
  while (N > R1) {
    numerator = ((long long)numerator * N) % p;
    N--;
  }

  int denominator = 1;
  while (R2 > 0) {
    denominator = ((long long)denominator * R2) % p;
    R2--;
  }

  return (int)(((long long)numerator * inv(denominator)) % p);
}

int main() {
  int X, Y; cin >> X >> Y;  
  
  // Pascal's traingle problem
  int ans = solve(X, Y);
  cout << ans << endl;
}