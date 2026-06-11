#include <bits/stdc++.h>
#define int long long int
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
void solve() {
 	int n;
  	cin >> n;
  	cout << min((n-1)/2, n/2) << '\n';
  	return ;
}
int32_t main() {
	fastio();
  	solve();
  	return 0;
}