#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rep(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define rrep(i, b, a) for(int (i) = (b); (i) > (a); (i)--)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, pair<int, int>> iii;

int arr[200'005];

int main() {
	FASTIO;
	int n; cin >> n;
	int ans;
	rep(i, 0, n) {
		int a; cin >> a;
		if (i == 0) ans = a;
		else ans ^= a;
		arr[i] = a;
	}

	rep(i, 0, n) {
		cout << (ans ^ arr[i]) << " ";
	}
	return 0;
}


