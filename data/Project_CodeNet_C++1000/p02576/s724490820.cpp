#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, t;
	cin >> n >> x >> t;
	int times=(n+x-1)/x;
	int ans=times*t;
	cout << ans << "\n";
}
