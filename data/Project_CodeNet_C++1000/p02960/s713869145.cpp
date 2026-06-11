#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, mod = 1e9 + 7;

string s;
int n, dp[13][N];

int power(int a, int b, int p){
	int ret = 1;
	a %= p;
	while(b > 0){
		if(b % 2 == 1)
			ret = ret * a % p;
		b /= 2;
		a = a * a % p;
	}
	return ret;
}

int go(int id, int rem){
	if(id >= n)
		return rem == 5;

	int &ans = dp[rem][id];
	if(~ans)
		return ans;
	ans = 0;

	if(s[id] != '?'){
		int dig = s[id] - '0';
		int next_rem = rem + dig * power(10, id, 13);
		ans = (ans + go(id + 1, next_rem % 13)) % mod;
	}else{
		for(int i = 0; i < 10; i++){
			int next_rem = rem + i * power(10, id, 13);
			ans = (ans + go(id + 1, next_rem % 13)) % mod;
		}
	}
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  

	memset(dp, -1, sizeof(dp));
	cin >> s;
	n = sz(s);
	reverse(s.begin(), s.end());
	cout << go(0, 0);
}
