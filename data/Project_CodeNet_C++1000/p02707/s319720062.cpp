#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PP pop_back
#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

	int n, a;
	cin >> n;
	int arr[n + 1];
	memset(arr, 0, sizeof arr);
	for (int i = 1; i < n; i++) {
		cin >> a;
		arr[a]++;
	}
	for (int i = 1; i <= n; i++) cout << arr[i] << endl;
	return 0;
}
