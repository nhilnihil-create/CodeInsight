#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) x.begin(), x.end()
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int cnt = 0;
	for(int i = 1; i < n - 1; i++) {
		if(v[i] < v[i - 1] && v[i] > v[i + 1]) {
			cnt++;
		} else if(v[i] > v[i - 1] && v[i] < v[i + 1]) {
			cnt++;
		}
	}
	cout << cnt << "\n";
}
