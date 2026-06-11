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
	int a; string s; cin >> a >> s;
	if(a >= 3200) println(s);
	else println("red");
}
