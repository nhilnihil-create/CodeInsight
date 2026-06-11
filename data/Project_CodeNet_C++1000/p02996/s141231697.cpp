#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int arr[60];
int n, p;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i].second;
		if (sum > v[i].first)
			return cout << "No\n", 0;
	}
	cout << "Yes\n";
}
