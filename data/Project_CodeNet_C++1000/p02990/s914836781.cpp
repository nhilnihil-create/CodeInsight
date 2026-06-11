#include <iostream>

using namespace std;

const int M = 1e9+7;
int n, k;
long long kaijo[2200];

int mpow(long long a, int n)
{
  if (n == 0) return 1;
  if (n % 2) return mpow(a, n-1) * a % M;
  return mpow(a * a % M, n / 2);
}

long long cmb(int n, int r)
{
  return kaijo[n] * mpow(kaijo[r], M-2) % M * mpow(kaijo[n-r], M-2) % M;
}

int main()
{
  cin >> n >> k;
  
  kaijo[0] = 1;
  for (int i = 1; i <= 2100; i++) {
    kaijo[i] = kaijo[i-1] * i % M;
  }
  
  for (int r = 1; r <= k; r++) {
    int ans = 0;
    if (n-k+1 >= r) {
      ans = cmb(k-1, r-1) * cmb(n-k+1, r) % M;
    }
    cout << ans << endl;
  }
  
  return 0;
}
