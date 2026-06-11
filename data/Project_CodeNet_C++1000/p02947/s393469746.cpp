#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	int n;
	cin >> n;
	vector<string>anaglam(n);
	map<string, ll>mp;
	for (int i = 0; i < n; i++) {
		cin >> anaglam[i];
		sort(anaglam[i].begin(), anaglam[i].end());
		mp[anaglam[i]]++;
	}
	ll sum = 0;
	for (auto id : mp) {
		sum += (id.second * (id.second - 1)) / 2;
	}
	cout << sum << endl;
	return 0;
}