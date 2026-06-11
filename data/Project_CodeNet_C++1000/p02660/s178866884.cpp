#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define PI acos(-1)
#define EPS 1e-5
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define forn(i, n) for(ll i=0;i<(ll)n;i++)
#define fi first
#define se second
 
map<ll, int> primes;

void primeFactors(ll n) {
	while(n % 2 == 0) {
		primes[2]++;
		n /= 2;
	}

	for(int i = 3; i <= sqrt(n); i += 2) {
		while(n % i == 0) {
			primes[i]++;
			n /= i;
		}
	}

	if(n > 2)
		primes[n]++;
}

int main() {
	ll n;
	cin >> n;
	primeFactors(n);
	int cnt = 0;
	for(auto i : primes) {
		cnt += (-1 + sqrt(1+8*i.se))/2;
	}
	cout << cnt << endl;
	return 0;
}

