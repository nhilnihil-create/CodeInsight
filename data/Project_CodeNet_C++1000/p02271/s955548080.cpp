#include "bits/stdc++.h"

using namespace std;

#define int long long
#define ll long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl


int table[50000];

signed main(){

	int n, q, a[20], m[200];
	cin >> n;
	rep(i, n) cin >> a[i];
	cin >> q;
	rep(i, q) cin >> m[i];

	rep(k, 1 << n){
		int t = 0;
		rep(bit, n){
			if ((1 << bit) & k) t += a[bit];
		}
		table[t]++;
	}

	rep(i, q){
		if (table[m[i]]) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}

