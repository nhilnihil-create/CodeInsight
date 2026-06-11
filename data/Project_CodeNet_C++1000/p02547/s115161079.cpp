#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int last = 0;
	bool yes = false;
	for(int i = 0; i < n; i ++) {
		int x, y; cin >> x >> y;
		if(x == y) last ++;
		else last = 0;
		if(last == 3) yes = true;
	}
	if(yes) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}