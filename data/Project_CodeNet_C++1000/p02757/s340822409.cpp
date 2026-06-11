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
	if(10 % p == 0 ){
		// p  = 5 か2
		ll ans = 0;
		rep(r,n){
			if((s[r] - '0') % p == 0) {
				// 右端がpの倍数なので，左箸が何通りあるか
				ans += r + 1;
			}
		}
		cout << ans << endl;
		return 0; //sample 2
	}

	vector<int> d(n+1);// 累積和 後ろから求めたい
	int ten = 1;
	for (int i = n-1; i >= 0; i--){
		int a = (s[i]-'0') * ten % p;
		d[i] = (d[i+1] + a) % p;
		ten *= 10; ten %= p;
	}
	vector<int> cnt(p);
	ll ans = 0;
	for (int i = n; i >= 0; i--){ // i = n -1 スタートだと違う
		ans += cnt[d[i]];
		cnt[d[i]]++;
	}
	cout << ans << endl;
	return 0;
}
