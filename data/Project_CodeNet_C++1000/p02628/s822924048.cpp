#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5+5;

int main() {

	IO;
	
	int n, k;
	cin >> n >> k;
	vector<int> ar(n);
	for (int i = 0; i < n; ++i) {
		cin >> ar[i];
	}
	int ans = 0;
	sort(ar.begin(), ar.end());
	for (int i = 0; k--; ++i) {
		ans+= ar[i];
	}
	
	cout << ans;
}
