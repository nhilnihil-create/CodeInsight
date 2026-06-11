#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5+5;

int main() {

	IO; 
	
	int n;
	cin >> n;
	int mx = 0;

	map<string, int> mp;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		mp[s]++;
		mx = max(mp[s], mx);
	}
	vector<string> best;
	
	for (auto it: mp) {
		if (it.second == mx) {
			best.push_back(it.first);
		}
	}

	
	sort(best.begin(), best.end());
	for (int i = 0; i < (int) best.size(); ++i) {
		cout << best[i] << endl;
	}
	
}
