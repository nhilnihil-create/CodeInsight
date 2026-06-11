#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}

template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}

int modpow(int a, int p) {
	if (p == 0)return 1;
	if (p % 2 == 0) {
		int halfP = p / 2;
		int half = modpow(a, halfP);
		return half * half%mod;
	}
	else {
		return a * modpow(a, p-1) % mod;
	}
}

signed main(void) {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int ret=0;
	rep(i,60){
		int zero = 0;
		rep(j,n){
			if(a[j]>>i&1)zero++;
		}
		int now = zero * (n-zero)%mod;
		now*=modpow(2,i);
		now%=mod;
		ret+=now;
		ret%=mod;
	}
	print(ret);
}