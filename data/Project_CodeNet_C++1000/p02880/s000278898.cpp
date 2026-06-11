#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1 << 29;
using ll = long long int;
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; ++i)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)


int main() {
	int n;
	cin >> n;
	bool b = false;
	rep(i, 9) {
		rep(j, 9) {
			if ((i + 1) * (j + 1) == n) {
				b = true;
				break;
			}
		}
	}

	cout << (b ? "Yes" : "No") << endl;
}