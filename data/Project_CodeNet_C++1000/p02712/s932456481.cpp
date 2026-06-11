#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	int n;
	cin >> n;
	ll sum = 0;
	for(int i = 1; i <= n; ++i) {
		if(i % 3 == 0 || i % 5 == 0) continue;
		sum += i;
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
