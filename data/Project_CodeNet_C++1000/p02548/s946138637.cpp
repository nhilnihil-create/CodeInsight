#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int ways = n / i - !(n % i);
		ans += ways;
	}
	cout << ans << '\n';
	return 0;
}