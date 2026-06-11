#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	int ans = 0;
	int keta = 0;
	int ntmp = N;
	while (0 != ntmp) {
		++keta;
		ntmp /= 10; 
	}
	map<int, int>mp;
	mp[1] = 0;
	mp[2] = 9;
	mp[3] = 9;
	mp[4] = 909;
	mp[5] = 909;
	mp[6] = 90909;
	ans += mp[keta];
	if (1 == keta%2) {
		ans += N - pow(10, keta - 1) + 1;
	}
	cout << ans <<endl;
	return 0;
}