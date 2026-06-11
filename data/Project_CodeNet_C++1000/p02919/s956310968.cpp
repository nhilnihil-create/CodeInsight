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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

int a[N], st[N][20], n;

int qry(int l, int r) {
	int g = __lg(r - l + 1);
	return max(st[l][g], st[r-(1<<g)+1][g]);
}

int ans;

void go() {
	for(int i=1;i<=n;i++)
		st[i][0] = a[i];
	for(int i=1;i<20;i++) {
		for(int j=1;j+(1<<i)-1<=n;j++) {
			st[j][i] = max(st[j][i-1], st[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<=n;i++) {
		int l = i+1, r = n;
		while(l <= r) {
			int m = (l + r) / 2;
			if(qry(i, m) > a[i])
				r = m - 1;
			else
				l = m + 1;
		}
 		int l2 = 1, r2 = i - 1;
		while(l2 <= r2) {
			int m = (l2 + r2) / 2;
			if(qry(m, i) > a[i])
				l2 = m + 1;
			else 
				r2 = m - 1;
		}
		int L = r2, R = l;
		if(R == n+1) continue;
		int cans = i - L;
		l = R+1, r = n;
		while(l <= r) {
			int m = (l + r) / 2;
			if(qry(R+1, m) > a[i])
				r = m - 1;
			else
				l = m + 1;
		}
		cans *= l - R;
		ans += cans * a[i];
	}
}

signed main()
{
	IO_OP;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	go();
	reverse(a+1, a+n+1);
	go();
	cout << ans << endl;
	
}
