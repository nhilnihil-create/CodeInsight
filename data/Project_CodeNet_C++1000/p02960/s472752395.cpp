#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define rep(pp,nn) for (int ii = pp; ii < nn; ++ii)
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

string int_to_string(int x) {
    stringstream ss;
	ss << x;
	string ni = ss.str();
	return ni;
}
int string_to_int(string x) {
	int n;
	stringstream s(x);
	s >> n;
	return n;
}

int64_t power_mod(ll a, ll b, ll mo) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = (ans % mo * a % mo) % mo;
		}
		a = (a % mo * a % mo) % mo;
		b /= 2;
	}
	return ans;
}
int64_t POW(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = ans * a;
		}
		a = a * a;
		b /= 2;
	}
	return ans;
}

vector<int64_t> INVERSE(int64_t nn, int64_t mo) {
	vector<int64_t> inv(nn + 1);
	vector<int64_t> mul(nn + 1);
	inv[0] = 1;
    inv[1] = 1;
	for (ll i = 2; i <= nn; ++i) {
		inv[i] = (mo - (mo / i) * inv[mo % i] % mo) % mo; 
	}
	mul[0] = 1;
	for (int i = 1; i <= nn; ++i) {
		mul[i] = (mul[i - 1] * inv[i]) % mo;
	}
	return mul;
}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



//int64_t rec(int index) {
	//if (index == n) {
		//return 0;
	//} 
	//for (int i = 0; i <= 9; ++i) {
		
	//}
//}

int main() {
	IOS;
	//string p = "0123456789";
	string s;
	int mod = 1e9 + 7;
	//int val = 13;
	cin >> s;
	int n = (int)s.size();
	vector<vector<int>> dp(n, vector<int> (13));
	//vector<int> dp(13);
	for (int i = 0; i < n; ++i) {
		//vector<int> new_dp(13);
		if (i == 0) {
			if (s[i] != '?') {
				dp[i][s[i] - '0']++;
			}else {
				for (int j = 0; j <= 9; ++j) {
					dp[i][j]++;
				}
			}
		}else {
			if (s[i] != '?') {
				///debug("hello");
				for (int j = 0; j < 13; ++j) {
					int x = (j * 10 + s[i] - '0') % 13;
					dp[i][x] = (dp[i - 1][j] + dp[i][x]) % mod;
				}
			}else{
				for (int k = 0; k < 13; ++k) {
					for (int j = 0; j <= 9; ++j) {
						int x = (k * 10 + j) % 13;
						dp[i][x] = (dp[i - 1][k] + dp[i][x]) % mod;
					}
				}
			}
		}
		//debug(dp);
		//debug(new_dp);
		//dp = new_dp;
	}
	//cout << dp[n - 1][5];
	cout << dp[n - 1][5];
	//cout << rec(0);
}















