#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int m;
  cin >> m;
  ll sum = 0, digit = 0;
  while (m--) {
    ll d, c;
    cin >> d >> c;
    sum += d * c;
    digit += c;
  }
  cout << (digit - 1) + ((sum - 1) / 9) << endl;
  return 0;
}