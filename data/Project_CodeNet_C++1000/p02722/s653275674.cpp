
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main(int argc, char* argv[]) {
	
	ll n;
	cin >> n;


	int cnt = 0;

	for (ll i = 2; i * i <=n; i++) {
		ll num = n;

		if (num % i != 0) {
			continue;
		}

		while (num % i == 0) {
			num /= i;
		}

		num %= i;

		if (num == 1) {
			cnt++;
			
		}
	}

	ll num = n - 1;


	 
	map<int, int> m;

	for (ll i = 2; i * i <= n; i++) {
		
		while (num % i == 0) {
			num /= i;
			m[i]++;
		}
	
	}

	if (num != 1) {
		m[num]++;
	}

	int c = 1;
	for (auto it = m.begin(); it != m.end(); it++) {
		c *= (it->second + 1);
	}
	

	cnt += c;

	cout << cnt << endl;
	
}