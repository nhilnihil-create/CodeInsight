#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>

#define vi vector<int>
#define tests int t; cin>>t; while(t--)
#define ll long long
#define vll vector<long long>

using namespace std;

char nums[10] = { '0','1','2','3','4','5','6','7','8','9' };
char alphsl[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

using namespace std;

void solve() {

	int n;
	cin >> n;
	vi v(n);
	for (auto& x : v) cin >> x;
	ll cnt = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (v[i] != v[j] && v[i] != v[k] && v[j] != v[k] && (v[i] + v[j] > v[k]) && (v[j] + v[k] > v[i]) && (v[i] + v[k] > v[j])) cnt++;
			}
		}
	}

	cout << cnt << endl;
}

int main() {
	
	solve();
	
	return 0;
}

