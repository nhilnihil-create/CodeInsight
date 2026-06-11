#include "bits/stdc++.h"
using namespace std;

//?????????
#pragma region MACRO 
#define putans(x)  std::cerr << "[ answer ]: " ; cout << (x) << endl
#define dputans(x) std::cerr << "[ answer ]: "; cout << setprecision(40) << (double)(x) << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define RREP(i,n,a) for(int i=(int)(n-1); i>= a; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,n,0)
#define all(a) begin((a)),end((a))
#define mp make_pair
#define exist(container, n) ((container).find((n)) != (container).end())
#define equals(a,b) (fabs((a)-(b)) < EPS)
#ifdef _DEBUG //???????????????????????????????????????????????????
std::ifstream ifs("data.txt");
#define put ifs >>
#else //?????£????????????????????§?????????????????????
#define put cin >>
#endif
#pragma endregion
//???????????°??????????????´
#pragma region CODING_SUPPORT
#ifdef _DEBUG
#define dbg(var0) { std::cerr << ( #var0 ) << "=" << ( var0 ) << endl; }
#define dbg2(var0, var1) { std::cerr << ( #var0 ) << "=" << ( var0 ) << ", "; dbg(var1); }
#define dbg3(var0, var1, var2) { std::cerr << ( #var0 ) << "=" << ( var0 ) << ", "; dbg2(var1, var2); }
#define dbgArray(a,n) {std::cerr << (#a) << "=";  rep(i,n){std::cerr <<(a[i])<<",";} cerr<<endl;} 
#else
#define dbg(var0) {}
#define dbg2(var0, var1) {}
#define dbg3(var0, var1, var2) {}
#define dbgArray(a,n) {}
#endif 
#pragma endregion 
//typedef????????????????????????????¶????????????§?????????
#pragma region TYPE_DEF
typedef long long ll;
typedef pair<int, int> pii; typedef pair<string, string> pss; typedef pair<int, string>pis;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
#pragma endregion
//??????????????°(???????????????????????§??????)
#pragma region CONST_VAL
#define PI (2*acos(0.0))
#define EPS (1e-10)
#define MOD (ll)(1e9 + 7)
#define INF (ll)(2*1e9)
#pragma endregion



const static int MAX_V = 10000;
vector<int> G[MAX_V];
int topologicalV[MAX_V];
int used[MAX_V];
int remain;

void dfs(int v) {
	if (used[v])return;
	if (G[v].size() == 0) {
		topologicalV[remain] = v;
		remain--;
		used[v] = true;
		return;
	}
	rep(i, G[v].size()) {
		if (!used[G[v][i]]) {
			dfs(G[v][i]);
		}
	}
	topologicalV[remain] = v;
	used[v] = true;
	remain--;
}

//AOJ GRL_5
int main() {
	int v,e; put v >> e;
	rep(i, e) {
		int from; put from;
		int to; put to;
		G[from].push_back(to);
	}
	remain = v-1;
	rep(i, v) {
		dfs(i);		
	}
	rep(i, v) {
		cout <<	topologicalV[i] << endl;
	}

END:

	return 0;
}