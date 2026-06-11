#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	ll n, k;
	cin >> n >> k;
	n %= k;
	cout << min(n, k - n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
