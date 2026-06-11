#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, mxK = 5e3 + 3;

int d[mxK];

signed main()
{
	IO_OP;
	
	int k, q;
	cin >> k >> q;
	for(int i=0;i<k;i++) cin >> d[i];
	while(q--) {
		int n, x, m, cnt = 0;
		cin >> n >> x >> m;
		for(int i=0;i<k;i++) if(d[i] % m == 0) cnt += (n - 1) / k + (i < (n-1) % k);
		ll sum = 0;
		for(int i=0;i<k;i++) sum += d[i] % m;
		ll y = x % m + (n - 1) / k * sum;
		for(int i=0;i<(n-1)%k;i++) y += d[i] % m;
		cnt += y / m;
		cout << n - 1 - cnt << endl;
	}
	
}



