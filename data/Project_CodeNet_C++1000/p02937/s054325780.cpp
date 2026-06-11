#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<random>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")


int main() {
	string s, t;
	cin >> s >> t;
	vector<array<int, 26>> table(s.size());
	for (auto& x : table)for (auto& y : x)y = -1;
	for (char i = 'a'; i <= 'z'; ++i) {
		int p, j = 0;
		for (; j < s.size(); ++j) {
			if (s[j] == i) {
				p = j;
				break;
			}
		}
		if (j == s.size())continue;
		int k = (j - 1 + s.size()) % s.size();
		for(int x = 0; x < s.size(); ++x) {
			table[k][i-'a'] = p;
			if (s[k] == i) p = k;
			k = (k - 1 + s.size()) % s.size();
		}
	}
	ll ans,p;
	auto st = s.find_first_of(t[0]);
	if (st == string::npos) {
		PRI(-1);
		return 0;
	}
	ans = st + 1;
	p = st;
	for (char& c : t.substr(1,t.size()-1)) {
		if (table[p][c - 'a'] == -1) {
			PRI(-1);
			return 0;
		}
		if (table[p][c - 'a'] <= p) ans += s.size() - p + table[p][c - 'a'];
		else ans += table[p][c - 'a'] - p;
		p = table[p][c - 'a'];
	}
	PRI(ans);
	return 0;
}


