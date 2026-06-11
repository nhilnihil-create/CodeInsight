#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int k;
	cin >> k;
	
	if( k < 10 ) {
		cout << k << endl;
		return 0;
	}
	
	queue<ll> q;
	vector<ll> lunlun;
	for(ll i = 1; i < 10; ++i) {
		q.push(i);
		lunlun.push_back(i);
	}
	
	int cnt = 9;
	while( cnt < k ) {
		ll now = q.front();
		q.pop();
		
		ll add = 10LL * now + (now % 10);
		
		if( now % 10 != 0 ) {
			lunlun.push_back(add - 1LL);
			q.push(add - 1LL);
			cnt++;
		}
		
		lunlun.push_back(add);
		q.push(add);
		
		if( now % 10 != 9 ) {
			lunlun.push_back(add + 1LL);
			q.push(add + 1LL);
			cnt++;
		}
		
		cnt++;
	}

	cout << lunlun[k - 1] << endl;
	
	return 0;
}
