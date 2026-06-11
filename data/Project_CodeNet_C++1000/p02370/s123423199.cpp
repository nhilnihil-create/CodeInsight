#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <numeric>
#include <climits>
#include <iterator>
#include <iomanip>
#include <stack>
#include <bitset>
#include <functional>
using namespace std;
//typedef std::pair<std::string,double> P;

typedef long long ll;
typedef vector<int> VI;

#define FOR(i, a, n) for (ll i = (ll)a; i<(ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)

//グラフの隣接リスト
VI g[100010];
//頂点の入次数を管理
int h[100010];
signed main(void) {

	//頂点数v, 辺の数e
	int v, e;
	cin >> v >> e;
	REP(i, e) {
		int s, t;
		cin >> s >> t;
		g[s].push_back(t); //sからtに向かう辺

		h[t]++;
	}
	stack<int> st;

	REP(i, v) if (h[i] == 0)st.push(i);
    
	//ソートされた後のグラフ
	VI ans;
	
	while (st.size()) {
		//stの集合から一つ取り出す
		int i = st.top(); st.pop();

		ans.push_back(i);

		for (auto& j : g[i]) {
			//隣接する頂点の入次数をマイナス1
			h[j]--;
			//これによって入次数が0になればstに追加
			if (h[j] == 0)st.push(j);
		}
	}

	for (auto i : ans) cout << i << endl;

	return 0;
}

