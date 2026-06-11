#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
 
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define speedhack() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define form(i, n) for (size_t i = 0; i < size_t(n); ++i)
#define forn(i, n) for (size_t i = 1; i <= size_t(n); ++i)
template<class T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
long long mod(long long a, long long b) { return (a%b+b)%b; }
long long gcd(long long x, long long y) { return __gcd(x, y); }
long long lcm(long long x, long long y) { return x * 1ll * y / gcd(x, y); }
 
 
const long long MAXN = 1e9 + 9;
const long long SIZE = 1e6 + 6;
const long long MOD  = 1e9 + 7;


long long N, G = -1, arr[SIZE], m[SIZE];
unordered_map<long long, long long> bag;

void prec () {

	for (long long i = 2; i <= 1000000; i++) {
		if (m[i] == 0) {
			m[i] = i;
			for (long long j = i * 1LL * i; j <= 1000000; j += i)
				m[j] = i;
		}
	}

}

void eraser (long long num) {
	while (num > 1) {
		bag[m[num]]--;
		num /= m[num];
	}
}

bool checker (long long num) {
	while (num > 1) {
		if (bag[m[num]] != 0)
			return true;
		num /= m[num];
	}
	return false;
}


int main() { speedhack()

	prec ();

	cin >> N;

	forn (i, N) {
		cin >> arr[i];
		if (G == -1)
			G = arr[i];
		else 
			G = gcd (G, arr[i]);
	}

	for (int i = N; i >= 1; i--) {
		long long temp = arr[i];
		while (temp > 1) {
			bag[m[temp]]++;
			temp /= m[temp];
		}
	}


	forn (i, N) {
		eraser (arr[i]);

		if (checker (arr[i])) {
			if (G == 1) 
				cout << "setwise coprime";
			else 
				cout << "not coprime";
			return 0;
		}
	}

	cout << "pairwise coprime";
	
	return 0;
}