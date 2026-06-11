#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) {  for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
int n;

vector <pair<int, int> > ans;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	if(n <= 2 || __builtin_popcount(n) == 1) {
		cout << "No\n";
		return 0;
	}


	if(n % 2 == 1) {
		for(int i = 2 ;i <= n; i += 2) {
			ans.push_back({i, i ^ 1});
			ans.push_back({1, i});
			ans.push_back({1, n + (i ^ 1)});
			ans.push_back({n + (i ^ 1), n + i});
		}
		ans.push_back({n + 1, 3});
	} else {
		int x = n;
		int p = -1;
		while(x) x /= 2, p++;
		for(int i = 2 ;i < n; i += 2) {
			if(i == (1 << p)) continue;
			ans.push_back({i, i ^ 1});
			ans.push_back({1, i});
			ans.push_back({1, n + (i ^ 1)});
			ans.push_back({n + (i ^ 1), n + i});
		}
		ans.push_back({n + 1, 3});

		x = n;
		int y = (1 << p);
		int z = (x ^ y);
		dbg(x, y, z);
		ans.push_back({n + z, y});
		ans.push_back({n + z, x});
		ans.push_back({n + x, y});
		ans.push_back({y ^ 1, y});
		ans.push_back({n + z ^ 1, n + (y ^ 1)});
		ans.push_back({n + (y ^ 1), n + y});
	}
	
	cout << "Yes\n" << ans << '\n';


}	

	