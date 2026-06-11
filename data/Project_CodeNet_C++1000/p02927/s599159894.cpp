#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
#define rSORT(a, i) sort(all(a),(i))

using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;
constexpr int MAX = 2000200;

using namespace std;

int main() {
	int m, d; 
	cin >> m >> d;

	int cnt = 0;

	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= d; j++) {
			int d10 = j / 10;
			int d1 = j % 10;

			if ((d1 * d10) == i && d1 >= 2 && d10 >= 2) {
				cnt++;
			}

		}
	}
	cout << cnt << endl;

	//cout << 24 % 10 << endl;
}


