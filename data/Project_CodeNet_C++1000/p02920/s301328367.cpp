#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<class U, class V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}


int main() {
	FAST_IO();
	int N, N2; cin >> N;
	N2 = 1 << N;
	vector<int> S(N2);
	rep(i, N2) cin >> S[i];
	// 좌표압축 O(N2)
	vector<int> A(N2);
	sort(all(S));
	int V = 0;
	rep(i, N2) {
		if(i == 0 || S[i] == S[i - 1]) A[i] = V;
		else A[i] = ++V;
	}
	vector<int> cnt(V + 1);
	rep(i, N2) cnt[A[i]]++;
	map<int, int> mp; // (number, remain)
	rep(i, V + 1) mp[-i] = cnt[i];
	multiset<int> mset;
	mset.insert(-V);
	rep(i, N) {
		/*for(auto &x : mset) cout << x << " ";
			cout << "~\n";
		for(auto &x : mp) cout << x << " ";
			cout << "\n";*/
		vector<int> add;
		for(auto &x : mset) {
			auto p = mp.upper_bound(x);
			if(p == mp.end()) continue;
			else {
				add.push_back(p->first);
				if(--p->second == 0) mp.erase(p);
			}
		}
		for(auto &x : add) mset.insert(x);
	}
	if(sz(mset) == N2) cout << "Yes\n";
	else cout << "No\n";
}