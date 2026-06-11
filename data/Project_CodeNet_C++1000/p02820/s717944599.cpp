#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t begin = clock();
	int n, k, r, s, p;
	cin >> n >> k;
	cin >> r >> s >> p;
	string str;
	cin >> str;
	int ans = 0;
	string used = "";
	for (int i = 0; i < int(str.size()); i++) {
		if (i < k) {
			if (str[i] == 'r')
				ans += p;
			if (str[i] == 'p')
				ans += s;
			if (str[i] == 's')
				ans += r;
		}
		else {
			if (str[i] == str[i - k])
				str[i] = '$';
			else {
				if (str[i] == 'r')
					ans += p;
				if (str[i] == 'p')
					ans += s;
				if (str[i] == 's')
					ans += r;
			}
		}
	}
	cout << ans << endl;
	clock_t end = clock();
	cerr << "Time run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
}