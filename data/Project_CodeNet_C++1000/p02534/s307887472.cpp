#include <bits/stdc++.h>
using namespace std;

#define len(s) int(s.size())
#define res(x) cout<<((x) ? "YES\n" : "NO\n")
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define st first
#define nd second

typedef long long int ll;
typedef long double ld;

void solution() {
	string s = "ACL", ans;
	int k; cin >> k;
	for(int i = 0; i < k; ++i) {
		ans += s;
	}
	cout << ans << endl;
}

int main() {
	
	int tt = 1;
	//cin >> tt;
	
	while(tt--) {
		solution();
	}
	
	return 0;
}
