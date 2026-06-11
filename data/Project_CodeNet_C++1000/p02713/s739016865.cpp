#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	int k;
	cin >> k;
	ll sum = 0;
	for(int a = 1; a <= k; ++a) {
		for(int b = 1; b <= k; ++b) {
			for(int c = 1; c <= k; ++c) {
				int f = __gcd(a, b);
				sum += __gcd(f, c);
			}
		}
	}
	
	cout << sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
