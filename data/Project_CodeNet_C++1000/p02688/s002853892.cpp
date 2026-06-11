#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<bool> has_snack(n, 0);
	for(int i = 0; i < k; ++i) {
		int qty;
		cin >> qty;
		for(int j = 0; j < qty; ++j) {
			int n_snuke;
			cin >> n_snuke;
			has_snack[n_snuke] = 1;
		}
	}
	
	int n_vic = 0;
	for(int i = 1; i <= n; ++i) {
		if(!has_snack[i]) ++n_vic;
	}
	
	cout << n_vic;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
