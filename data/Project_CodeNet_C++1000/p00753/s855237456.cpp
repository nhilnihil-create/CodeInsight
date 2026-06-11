#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = (1LL << 31) - 1;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1
#define MAX_N 100100 * 3

int n;
int cnt[300000];

bool is_prime[300000];

int sieve(int n) {
	int p = 0;
	for (int i = 0; i <= n; i++)is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			for (int j = 2 * i; j <= n; j += i)is_prime[j] = 0;
		}
	}
	return p;
}

int main() {
	sieve(300000 - 1);
	FOR(i, 1, 300000) {
		cnt[i] = cnt[i - 1] + is_prime[i];
	}
	while (cin >> n &&n) {
		cout << cnt[2 * n] - cnt[n] << endl;
	}
}