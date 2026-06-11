#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10;



int main()
{
    fastInp;

    ll n;
	cin >> n;

	for (ll i = 0; i <= n; i++) {
		if ((i * 108) / 100 == n) {
			cout << i;
			return 0;
		}
	}

	cout << ":(";

    return 0;
}