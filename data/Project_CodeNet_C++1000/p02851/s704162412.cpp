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

#define REP(i,a,b) for(int i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")



int main() {
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N+1);
	vector<ll> S(N + 1);
	REP(i, 1, N+1) cin >> A[i];
	S[0] = 0;
	REP(i, 0, N)S[i + 1] = S[i] + A[i+1];
	unordered_map<ll, int> mp;
	ll ans = 0;
	mp[0] = 1;
	REP(j, 1, N+1) {
		ll x = (S[j] - j) % K;
		if (j >= K) mp[(S[j - K] - (j - K)) % K]--;
		ans += (mp.count(x) > 0) ? mp[x] : 0;
		mp[x]++;
	}
	PRI(ans);
	return 0;
}


