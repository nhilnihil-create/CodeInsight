#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	int n;
	cin >> n;
	set<string> items;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		items.insert(s);
	}
	
	cout << items.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
