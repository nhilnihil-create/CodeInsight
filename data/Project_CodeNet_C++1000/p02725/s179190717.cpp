#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	int k, n;
	cin >> k >> n;
	vector<int> dis(n);
	for(int i = 0; i < n; ++i) cin >> dis[i];
	int bigger = 0;
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		int value;
		if(i < n - 1) {
			value = dis[i+1] - dis[i];
			sum += value;
		} else {
			value = k - dis[i] + dis[0];
			sum += value;
		}
		
		if(value > bigger) bigger = value;
	}
	cout << sum-bigger;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}
