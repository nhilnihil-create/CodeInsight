#include <bits/stdc++.h>
using namespace std;

int main() {
	//37c
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	typedef long long ll;
	vector<ll> a(n), b(n);
	for (ll &p:a) cin>>p;
	for (ll &p:b) cin>>p;
	typedef pair<ll, int> pii;
	priority_queue<pii> Q;
    for (ll i = 0; i < n; i ++) {
		if (b[i] < a[i]) {
			cout<<-1;
			return 0;
		}
		else if (b[i] > a[i]) Q.emplace(b[i], i);
    }
    long long ans = 0;
    while (!Q.empty()) {
        int i = Q.top().second; Q.pop();

		ll to = max(b[(i+1)%n], b[(i+n-1)%n]);

		ll sum = b[(i+1)%n] + b[(i+n-1)%n];

		if (b[i] < sum) {
			cout<<-1;
			return 0;
		}

        if (a[i] >= to) {
			if ((b[i] - a[i]) % sum) {
				cout<<-1;
				return 0;
			}
			ans += (b[i] - a[i]) / sum;
			b[i] = a[i];
        }

        else {
			ll step = (b[i] - to) / sum + 1;
			b[i] -= step * sum;
			if (b[i] < a[i]) {
				cout<<-1;
				return 0;
			}
			ans += step;
			if (b[i] > a[i]) Q.emplace(b[i], i);
        }
    }
    cout<<ans;
	return 0;
}
