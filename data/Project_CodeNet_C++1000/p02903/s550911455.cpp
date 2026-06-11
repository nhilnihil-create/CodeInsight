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

	ll h, w, a, b;
	cin >> h >> w >> a >> b;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if ((j < a && i < b) || (j >= a && b <= i)) {
				cout << "1";
			} else {
				cout << "0";
			}
			
		}
		cout << "\n";
	}
	return 0;
}