#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	map<int, int> mp;
	cin >> n;
	long long answer = 0;
	for (int i = 1; i <= n; ++i) {
		int ai;
		cin >> ai;
		answer += mp[i - ai];
		++mp[i + ai];
	}
	cout << answer;
}