#include <cstdio>
#include <iostream>

using namespace std;

int N;
static const int MAX = 1000000;
bool isPrime[MAX];

void solve(int n) {
  int n_2 = n * 2;
  int cnt = 0;
  for (int i = n + 1; i <= n_2; i++) {
    if (isPrime[i]) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}

void init() {
  isPrime[0] = isPrime[1] = false;
  fill(isPrime, isPrime + MAX, true);
  for (int i = 2; i * i < MAX; i++) {
    for (int j = i + i; j < MAX; j += i) {
      isPrime[j] = false;
    }
  }
}

int main() {
  init();
  while (cin >> N) {
    if (N == 0) {return 0;}
    solve(N);
  }
}