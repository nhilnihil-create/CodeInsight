#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL V, E; cin >> V >> E;
		vector<vector<UL>> G(V);
		vector<UL> ins(V);
		rep(i, E) {
			UL a, b; cin >> a >> b;
			G[a].push_back(b);
			ins[b]++;
		}
		queue<UL> Q;
		rep(i, V) if (ins[i] == 0) Q.push(i);
		vector<UL> tro;
		while (Q.size()) {
			UL p = Q.front(); Q.pop();
			tro.push_back(p);
			for (UL e : G[p]) {
				ins[e]--;
				if (ins[e] == 0) Q.push(e);
			}
		}
		rep(i, tro.size()) cout << tro[i] << endl;
	}


	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}
