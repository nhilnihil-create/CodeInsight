#include<iostream>
#include<string>
using namespace std;

int pow_mod(int a, int b, int div) {
  if (b == 0) return 1;
  if (b == 1) return a;
  int x = pow_mod(a, b/2, div);
  x = (long)x * x % div;
  if (b % 2) x = (long)x * a % div;
  return x;
}

int main() {
  int DIV = 1e+9 + 7;
  string S; cin >> S;
  int N = S.size();
  int k = 1, sum = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '1') {
      sum = ((long)sum + (long)k * pow_mod(3, N - i - 1, DIV)) % DIV;
      k = k * 2 % DIV;
    }
  }
  sum = (sum + k) % DIV;
  cout << sum << endl;
}