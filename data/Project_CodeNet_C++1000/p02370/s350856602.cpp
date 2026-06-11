#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)


int main() {
	int n, m;
	cin >> n >> m;
	vector<int>in(n);
	vector<int>e[101010];
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].pb(y);
		in[y]++;
	}

	stack<int>st;
	for (int i = 0; i < n; i++)if (!in[i])st.push(i);

	vector<int>ans;
	while (st.size()) {
		int i = st.top();
		st.pop();
		ans.pb(i);
		fore(x, e[i]) {
			in[x]--;
			if (!in[x])st.push(x);
		}
	}

	if (ans.size() != n)puts(-1);
	else {
		fore(x, ans)puts(x);
	}

	return 0;
}
