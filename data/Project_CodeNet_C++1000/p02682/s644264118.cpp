#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	ll sum = 0;
	sum += min(a, k) * 1;
	k -= a;
	k = max(k, (ll)0);
	sum += min(b, k) * 0;
	k -= b;
	k = max(k, (ll)0);
	sum += min(c, k) * -1;
	cout << sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
