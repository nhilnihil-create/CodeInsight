#include <bits/stdc++.h>

#define F first
#define S second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define in(x) insert(x)
#define forr(i, a, b) for(int i = a;i <= b;i++)
#define sz(s) (int)(s.size())
#define all(x) x.begin(), x.end()
#define did_you_calis_enough ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define int long long

using namespace std;

const int INF =  4294967295;
const int  N = 2e6 + 667;
const int mod = 1e9 + 7;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const double PI = acos(-1.0);

vector <int> a;

void input(int &n, int &k){
	cin >> k >> n;
	for(int i = 0;i < n;i++){
		int t;
		cin >> t;
		a.pb(t);
	}
}

main() {
	did_you_calis_enough
	int n, k;
	input(n, k);
	sort(all(a));
	int mx = -1;
	for(int i = 1;i < n;i++)
	 	mx = max(mx, abs(a[i] - a[i-1]));
	cout << k - max(mx, (k - a[--n]) + a[0]);
	return 0;
}

//Coded by LoliThief