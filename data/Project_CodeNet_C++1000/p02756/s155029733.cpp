#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cmath>
#include<bitset>
#include<string>
#include<deque>
typedef long long ll;
#define PB	push_back
#define FOR(n)			for(int i = 0; i < n; ++i)
#define RFOR(n)			for(int i = n; i >= 0; --i)
#define FORR(start,end) for(int i = start; i < end; ++i)
#define COUT(n)			cout << n << " " << flush
#define vi(v)			vector<int> v
#define vii(v)			vector<pair<int,int>> v
#define pii(p)			pair<int,int> p
#define mii(m)			map<int, int> m
#define msi(m)			map<string, int, less<>> m
#define mmsi(m)			multimap<string, int, less<>> m
#define mkp(a,b)		make_pair(a,b)
#define ALL(obj)		obj.begin(), obj.end()
const double PI	 = 3.141592;
const int	 MOD = 1e9 + 7;
using namespace std;

void solve() {
	int q, t, f;
	bool re = false;
	char c;
	string str;	cin >> str;
	deque<char> s(str.size());
	for(int i = 0; i < str.size(); ++i) s[i] = str[i];
	cin >> q;
	for(int i = 0; i < q; ++i) {
		cin >> t;
		if(t == 1) { re = !re; continue;}
		cin >> f;
		cin >> c;
		if(f == 1) {
			if(re) s.push_back(c);
			else s.push_front(c);
		}
		else {
			if(re) s.push_front(c);
			else s.push_back(c);
		}
	}
	if(re)
		for(int i = s.size()-1; i >= 0; --i) cout << s[i];
	else
		for(int i = 0; i < s.size(); ++i) cout << s[i];
	cout << endl;
}

int main() {
	solve();
	return 0;
}