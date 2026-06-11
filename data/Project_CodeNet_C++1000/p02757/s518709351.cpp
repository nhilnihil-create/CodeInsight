#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)


// Write From This Line
int main()
{
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;

	if( 10 % p == 0) {
		ll ans = 0;
		rep(l,n){
			if ( (s[l] - '0') % p == 0){
				ans += l + 1;
			}
		}
		cout << ans << endl;
		return 0;
	}
	ll ans = 0;
	vector<int> d(n+1); // 累積和用のテーブル
	int ten = 1;
	for(int i = n - 1; i >= 0; i--) {
		int a = (s[i] - '0') * ten % p;
		d[i] = (d[i+1] + a) % p; 
		ten *= 10;
		ten %= p;
	}
	vector<int> cnt(p+1);
	rep(i,n+1){
		ans += cnt[d[i]]++;
	}
	cout << ans << endl;
}
