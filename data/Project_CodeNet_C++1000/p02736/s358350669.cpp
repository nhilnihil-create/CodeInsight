#include <iostream>

using namespace std;

int const nmax = 1000000;
char v[1 + nmax];

int legendre(int n, int k){
  int result = 0;
  for(int i = k; i <= n; i *= k)
    result += n / i;
  return result;
}

int comb(int n, int k){
  return legendre(n, 2) - legendre(k, 2) - legendre(n - k, 2);
}

int solve(int n){
  int result = 0;
  for(int i = 1;i <= n; i++)
    if(0 == comb(n - 1, i - 1))
      result ^= v[i];
  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    v[i] -= '1';
  }

  bool mode = 0;
  for(int i = 1;i <= n; i++)
    mode |= (v[i] == 1);
  if(mode == 1){
    for(int i = 1;i <= n; i++)
      if(v[i] == 2)
        v[i] = 0;
    cout << solve(n);
  } else {
    for(int i = 1;i <= n; i++)
      if(v[i] == 2)
        v[i] = 1;
    cout << solve(n) * 2;
  }
  return 0;
}
