#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll mod = 1000000007;

int main() {
	ll x;
	cin >> x;
	for (ll a = -1000; a <= 1000; a++) {
		for (ll b = -1000; b <= 1000; b++) {
			if ((a * a * a * a * a) - (b * b * b * b * b) == x) {
				cout << a << " " << b << endl;
				return 0;
			}
		}
	}
	return 0;
}
