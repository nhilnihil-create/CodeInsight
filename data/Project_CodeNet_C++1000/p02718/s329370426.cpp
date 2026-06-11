#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	ll sum = 0;
	for (int x : a) sum += x;
	int good = 0;
	for (int x : a) if (x * 4ll * m >= sum) good++;
	cout << (good >= m ? "Yes" : "No");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
