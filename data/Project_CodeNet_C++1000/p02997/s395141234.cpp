#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#include <stack>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 1000000000000

using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int G[101][101];

int main () {
	int N, K;
    cin >> N >> K;
	if (K > (N-1)*(N-2)/2) {
		cout << -1 << endl;
		return 0;
	}
	vector<pii> ans;
	rep(i,N-1) ans.push_back(pii(i+1, N));
	vector<pii> edges;
	rep(i,N-1)
		rep(j,i)
			edges.push_back(pii(j+1,i+1));
	rep(i,(N-1)*(N-2)/2 - K) ans.push_back(edges[i]);
	cout << ans.size() << endl;
	rep (i,ans.size()) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
    return 0;
}