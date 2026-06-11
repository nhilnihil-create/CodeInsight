#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <bit>
#include <bitset>
#include <iomanip>
#include <queue>
typedef long long int ll;
using namespace std;
int main() {
	int N; cin >> N;
	vector<ll>data(N);
	for (int i = 0; i < N; i++)cin >> data[i];
	sort(data.begin(), data.end());
	bool ans = true;
	for (int i = 0; i < N -1 ; i++) {
		if (data[i] == data[i + 1])ans = false;
	}
	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}