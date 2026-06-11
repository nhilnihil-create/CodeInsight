// "for if god is with them who can be against them."
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define endl '\n'
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
void solve() {
	int h1, m1, h2, m2, k;
	cin >> h1 >> m1 >> h2 >> m2 >> k;
	int tot = (h2 - h1) * 60 + (m2 - m1);
	cout << tot - k;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	IOS;
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}


#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
	return 0;
}