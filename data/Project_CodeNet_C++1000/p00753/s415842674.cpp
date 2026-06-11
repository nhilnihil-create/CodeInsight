#include <bits/stdc++.h>

using namespace std;

#define LOG(...) fprintf(stderr, __VA_ARGS__)
//#define LOG(...)
#define FOR(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SQ(n) (n) * (n)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 123456 * 2;
bool sieve[N + 1];
int number[N + 1];

int main() {
  int cnt = 0;
  FOR(i, 2, N + 1){
    number[i] = cnt;
    if (sieve[i]) continue;
    number[i] = ++cnt;
    for(int j = i * 2; j < N  + 1; j += i) {
      sieve[j] = true;
    }
  }

  int n;
  while(cin >> n, n) {
    cout << number[2 * n] - number[n] << endl;
  }
}