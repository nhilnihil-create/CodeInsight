#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    int l, r;
	cin >> l >> r;
	int m = 2019;

	int ans = INF;
	for(int i = l; i < r; i++){
		for(int j = l+1; j <= r; j++){
			ans = min(ans, ((i % m) * (j % m)) % m);
			if (ans == 0){
				cout << ans << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
}
