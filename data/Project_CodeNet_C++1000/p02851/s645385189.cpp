
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;




int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> sum(n + 1);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum[i + 1] = (sum[i] + a);
	}
	map<ll, int>m;
	m[0]++;
	ll cnt = 0;
	for (int i = 1;i <=n;i++) {
		
		if (i >= k) {

			int s1 = (sum[i - k] - (i - k)) % k;
			m[s1]--;
		}
		int s = (sum[i] - i) % k;
		cnt += m[s];
		m[s]++;
		
		
		
	}


	cout << cnt << endl;
}

