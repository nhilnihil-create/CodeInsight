#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <bit>
#include <bitset>
#include <cstdint>
#include <iomanip>
#include <queue>
#include <initializer_list>
#include <stdio.h>
typedef long long int ll;
using namespace std;
int main() {
	int N, K; cin >> N >> K;
	vector<ll>data(N);
	ll ans = 0;
	for (int i = 0; i < N; i++)cin >> data[i];
	sort(data.begin(), data.end());
	reverse(data.begin(), data.end());

	if (K >= N) {
		cout << 0 << endl;
	}
	else {
		data.erase(data.begin(),data.begin()+K);
		for (int i = 0; i < data.size(); i++)ans += data[i];
		cout << ans << endl;
	}
}