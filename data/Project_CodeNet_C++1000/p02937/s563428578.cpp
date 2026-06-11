#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

// numよりも大きい最小の値のindexを返したい
int binarySearch(int num, vector<int> &L) {
	int left = -1;
	int right = L.size();
	int mid = (right + left) / 2;
	while (right - left > 1) {
		mid = (right + left) / 2;
		if (L[mid] > num)right = mid;
		else left = mid;
	}
	return L[right];

}

int main() {
	string s, t; cin >> s >> t;
	map<char, vector<int>> mp;
	rep(i, s.size()) {
		mp[s[i]].push_back(i + 1);
	}

	long long ans = 0;
	int place = 0;
	rep(i, t.size()) {
		if (mp[t[i]].size() == 0) {
			cout << -1;
			return 0;
		}
		if (mp[t[i]][mp[t[i]].size() - 1] <= place) {
			ans += s.size();
			place = mp[t[i]][0];
		}
		else {
			int num = binarySearch(place, mp[t[i]]);
			//cout << "binary: " << num << endl;
			place = num;
		}
		//cout << place << endl;
		//cout << ans << endl;
	}
	cout << ans + (long long)place;
}