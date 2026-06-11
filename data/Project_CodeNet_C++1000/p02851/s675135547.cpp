#define NguyenDangQuan the_author

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define mset(x, i) memset(x,i,sizeof(x))
#define elif else if
#define heap priority_queue
#define fi first
#define se second
#define pb push_back
#define ld long double
#define ll long long
#define int long long
#define task ""
using namespace std;

int typetest;
template<class T>
void read(T &x){
    register int c;
    T neg = 1;
    x = (T)0;
    while ((c = getchar()) <= 47 || c >= 58)
		if(c == '-') neg = -1;
    for (; (c > 47 && c < 58); c = getchar()){
        x = (x << 3) + (x << 1) + (T)(c - 48);
    }
	x *= neg;
}
inline void fastIOfileinput(){
	ios_base:: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen(task".INP", "r", stdin);
//	freopen(task".OUT", "w", stdout);
//	freopen(task".in", "r", stdin);
//	freopen(task".out", "w", stdout);
	typetest = 0;
}

const int N = 2e5 + 2;
int n;
ll k, a[N], l = 0;
map<int, vector<int>> b;
set<int> s;

void Enter(){
	read(n); read(k);
	s.insert(0);
	b[0].pb(0);
	for(int i = 1; i <= n; ++i){
		read(a[i]);
		a[i] += a[i - 1];
		a[i] %= k;
		s.insert(((a[i] % k - i) % k + k) % k);
		b[((a[i] % k - i) % k + k) % k].pb(i);
	}
}

void Solve(){
	ll ans = 0;
	for(auto i : s){
		auto& q = b[i];
		for(int t = 0; t < q.size(); ++t){
			int j = q[t];
			int l = t + 1, m, h = q.size() - 1;
			while(l <= h){
				m = (l + h) >> 1;
				if(j + k > q[m]) l = m + 1;
				else h = m - 1;
			}
			ans += (ll)(h - t);
		}
	}
	cout << ans;
}

signed main(){
	fastIOfileinput();
	if(typetest){
		int t;
		cin >> t;
		while(t--){
			Enter();
			Solve();
		}
	}
	else{
		Enter();
		Solve();
	}
}
