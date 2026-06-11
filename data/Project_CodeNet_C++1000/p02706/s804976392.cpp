#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for(int i = 0; i < m; ++i) {
		int value;
		cin >> value;
		sum += value;
	}
	cout << max((n - sum), -1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
