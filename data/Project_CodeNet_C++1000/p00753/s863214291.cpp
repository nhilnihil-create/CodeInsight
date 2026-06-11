#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

const int SIZE = 123456 * 2;
int prime[SIZE + 10];
bool bprime[SIZE + 10];
int psize = 0;

int main() {
  MEMSET(bprime, true);
  FOREQ(i, 2, SIZE) {
    if (!bprime[i]) { continue; }
    prime[psize++] = i;
    for (int j = i + i; j <= SIZE; j += i) {
      bprime[j] = false;
    }
  }
  int n;
  while (scanf("%d", &n), n) {
    int ans = 0;
    FOREQ(i, n + 1, 2 * n) {
      ans += bprime[i];
    }
    cout << ans << endl;
  }
}