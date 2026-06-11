#include <bits/stdc++.h>
#define N (long long)(1e9 + 7)
#define MAX 500000
using namespace std;

long long factorial[MAX] = {0}, finverse[MAX] = {0},
          inverse[MAX] = {0};

void smodfact() {
  factorial[0] = factorial[1] = 1;
  finverse[0] = finverse[1] = 1;
  inverse[1] = 1;
  for(int i = 2; i < MAX; ++i) {
    factorial[i] = factorial[i - 1] * i % N;
    inverse[i] = N - (inverse[N % i] * (N / i)) % N;
    finverse[i] = finverse[i - 1] * inverse[i] % N;
  }
}

long long calccomb(long long n, long long k) {
  if(n == k && n == 0) return 1;
  if(n < 0 || k < 0 || n < k) return 0;
  return factorial[n] * finverse[k] % N * finverse[n - k] %
         N;
}

long long n;
string s;

long long solve();

int main() {
  cin >> n >> s;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long cnt = 1, ans = 1;
  smodfact();
  if(s[0] == 'W' || s[2 * n - 1] == 'W') return 0;
  ans = factorial[n];
  for(int i = 1; i < 2 * n; ++i)
    if(cnt % 2 == (s[i] == 'W'))
      ++cnt;
    else
      (ans *= cnt--) %= N;
  if(cnt != 0) return 0;
  return ans;
}