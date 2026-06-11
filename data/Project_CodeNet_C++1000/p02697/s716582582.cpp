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
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(int i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")


int main() {
	int N, M;
	cin >> N >> M;
	int kl, kr, gl, gr;
	kl = 1;
	kr = 2*((N+1) / 4);
	gl = kr + 1;
	gr = (N % 2 == 0) ? N - 1 : N;
	bool next_k = true;
	for (int i = 0; i < M; ++i) {
		if (next_k) {
			PRI(kl <<" "<< kr);
			++kl;
			--kr;
			next_k = false;
		}
		else {
			PRI(gl <<" "<< gr);
			++gl;
			--gr;
			next_k = true;
		}
	}
	return 0;
}


