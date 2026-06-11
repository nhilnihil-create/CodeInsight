/*dismint|jjc*/
#include <bits/stdc++.h>
using namespace std;
#define forl(V, S, E) for(int V = S; V < E; V++)
#define ford(V, S, E) for(int V = S; V >= E; V--)
#define fore(E, X) for(auto &E:X)
#define println(X) cout << X << endl
#define printe(X) for(auto &E:X) cout << E << " "; cout << endl
typedef unordered_map<int, unordered_set<int>> graph;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s, t; cin >> s >> t;
	set<char> c1; fore(e, s) c1.insert(e);
	fore(e, t) if(!c1.count(e)) { println("-1"); return 0; }
	map<char, set<int>> occ;
	forl(i, 0, s.length()) occ[s[i]].insert(i);
	ll pos = -1, its = 0;
	fore(e, t) {
		auto it = occ[e].upper_bound(pos);
		if(it == occ[e].end()) {
			pos = *occ[e].begin();
			its++;
		}
		else {
			pos = *it;
		}
	}
	println((int)s.length()*its+pos+1);
}
