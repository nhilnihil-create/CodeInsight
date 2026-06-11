#include <bits/stdc++.h>
using namespace std;

long long n, a, b, ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> a >> b;
	if(a < b)
		swap(a, b);
	if((a - b) % 2 == 0) {
		ans = (a - b) / 2;
	} else {
		ans = min(b + (a - b - 1) / 2, n - a + 1 + (a - b - 1) / 2);
	}
	cout << ans << "\n";
	return 0;
}