#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;


const int BIG_NUM = 1e8;
const ll INF = 1000000000000000000;

int main() {

	ll n;
	cin >> n;

	map <ll, int> m;

	ll num = n;
	for (ll i = 2; i * i <= n; i++) {
		while (num % i == 0) {
			m[i]++;
			num /= i;
			
		}

		
	}

	if (num != 1) {
		m[num]++;
	}

	set<ll> s;

	for (auto it = m.begin(); it != m.end();it++) {
		if (it->second == 0) {
			continue;
		}

		ll z = it->first;
		for(int j = 0;j <it->second;j++){
			s.insert(z);
			z *= it->first;

			
		}
	}

	

	num = n;
	int cnt = 0;
	
	for (auto it = s.begin(); it != s.end(); it++) {
		
		if (num % *it ==0) {
			cnt++;
			num /= *it;
		}
	}
	cout << cnt << endl;
}