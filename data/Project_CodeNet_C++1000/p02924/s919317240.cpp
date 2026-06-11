#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int) (n); i++)
#define ll long long
ll INF = 9e17;
ll mod = 1e9 + 7;

int main() {
	int n; cin >> n;
	ll ans = 0;
	for(int i=1;i<=n-1;i++) {
		ans+=i;
	}
	cout << ans << endl;
}