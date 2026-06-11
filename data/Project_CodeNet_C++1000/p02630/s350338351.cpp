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

map<int , int > m;

void input(int &n, int &sum){
	cin >> n;
	for(int i = 0;i < n;i++){
		int t;
		cin >> t;
		m[t]++;
		sum += t;
	}
}



main() {
	did_you_calis_enough
	int n, sum = 0, q;
	input(n, sum);
	cin >> q;
	while(q--){
		int p, x;
		cin >> p >> x;
		sum -= m[p] * p;
		sum += m[p] * x;
		m[x] += m[p];
		m[p] = 0;
		cout << sum << '\n';
	}
	return 0;
}

//Coded by LoliThief