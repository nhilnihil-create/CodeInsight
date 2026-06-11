#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
//		freopen("in1.txt", "r", stdin);
//		freopen("in1.txt", "w", stdout);
	#endif
	string s;
	cin >> s;
	int cnt = 0;
	for (char x : s) cnt += (x == 'R');
	if (cnt == 2 && s[1] == 'S') cnt--;
	cout << cnt << '\n';
}