#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;
	s.push_back('Z');

	vector <int> v;
	int cnt = 1;
	for (int ii = 0; ii < n; ++ii){
		if (s[ii] != s[ii+1]){
			v.push_back(cnt);
			cnt = 1;
		} else {
			cnt++;
		}
	}

	int limit = v.size();
	int ans = v[0];
	int idx = 1;
	cnt = 0;
	while (idx < limit) {
		//1回目
		ans += v[idx];
		idx++;
		if (idx == limit){
			break;
		}
		//2回目
		ans += v[idx];
		idx++;
		if (idx == limit){
			break;
		}
		cnt++;
		if (cnt == k){
			break;
		}
	}
	ans--;

	for (int ii = idx; ii < limit; ++ii){
		ans += v[ii] - 1;
	}

	cout << ans << "\n";

	return 0;
}
