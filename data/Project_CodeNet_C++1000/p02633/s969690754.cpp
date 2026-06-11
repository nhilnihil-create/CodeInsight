#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, ans = 0;
	cin >> n;
	int amt = n;
	while(amt % 360 != 0) {
		amt += n;
		ans++;
	}
	cout << ans+1 << endl;
}