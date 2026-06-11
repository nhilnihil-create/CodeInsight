#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	ll x;
	cin >> x;
	ll years = 0;
	ll money = 100;
	while(money < x) {
		money += (money * 1) / 100;
		++years;
	}
	cout << years;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
