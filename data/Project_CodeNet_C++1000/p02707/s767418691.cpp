#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	int n;
	cin >> n;
	vector<vector<int>> suc(n+1);
	for(int i = 2; i <= n; ++i) {
		int value;
		cin >> value;
		suc[value].emplace_back(i);
	}
	
	for(int i = 1; i <= n; ++i) {
		cout << suc[i].size() << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
