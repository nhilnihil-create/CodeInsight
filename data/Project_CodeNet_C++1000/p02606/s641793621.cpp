#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setbits(x) __builtin_popcount(x)
#define zerobits(x) __builtin_ctz(x)
#define setbitsll(x) __builtin_popcountll(x)
#define zerobitsll(x) __builtin_ctzll(x)
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef map<int,int> mii;

const int MOD = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l,r,d,cnt = 0;
	cin >> l >> r >> d;
	for (int i = l;i <= r;++i) {
		if (i%d == 0) {
			++cnt;
		}
	}
	cout << cnt << '\n';
	return 0;
}

