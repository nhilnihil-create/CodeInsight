//#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair

typedef long long ll;
typedef unsigned long long int ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;

typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<int> vi;

typedef map<string, int> msi;
typedef map<int, int> mii;
typedef map<int, ll> mill;
typedef map<int, vi> mivi;

const int MAXN = 1e5;
const int MAXM = 13;
const int MOD = 1e9 + 7;

int memo[MAXN][MAXM];

string S;
int n;

void fast_io() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
}

int solve(int pos, int mod) {
	if(pos == n)
		return mod == 5;
	
	if(memo[pos][mod] != -1)
		return memo[pos][mod];
	
	int res = 0;
	if(S[pos] == '?') {
		for(int i = 0; i <= 9; i++)
			res = (res + solve(pos + 1, (mod * 10 + i) % MAXM)) % MOD;
	}
	else res = (res + solve(pos + 1, (mod * 10 + (S[pos] - '0')) % MAXM)) % MOD;
	
	return memo[pos][mod] = res;
}

int main() {
	fast_io();
//	freopen("input/ABC135D.txt", "r", stdin);
	
	cin >> S;
	
	n = S.length();
	memset(memo, -1, sizeof(memo));
	
	cout << solve(0, 0) << '\n';
	
	return 0;
}