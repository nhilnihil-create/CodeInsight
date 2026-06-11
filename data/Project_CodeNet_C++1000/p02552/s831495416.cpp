#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve() {
	int x;
	scanf("%d", &x);
	if (x == 1)
		printf("%d\n", 0);
	else
		printf("%d\n", 1);

}

int main()
{
	startTime = clock();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//scanf("%d", &t);
	while (t--) solve();

	return 0;
}
