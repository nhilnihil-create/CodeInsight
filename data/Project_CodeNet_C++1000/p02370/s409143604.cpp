#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

#include <cstdio>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;


vector<int> DAG[10000];
vector<int> ans;
bool done[10000] = { false };
int indeg[10000] = { 0 };

int main()
{
	int V, E;
	int s, t;
	queue<int> Q;

	cin >> V >> E;
	rep(i, E) {
		cin >> s >> t;
		DAG[s].push_back(t);
		indeg[t]++;
	}

	rep(i, V) {
		if (indeg[i] == 0 && !done[i]) {
			Q.push(i);

			while (!Q.empty()) {
				s = Q.front(); Q.pop();
				done[s] = true;
				ans.push_back(s);

				rep(j, DAG[s].size()) {
					t = DAG[s][j];
					indeg[t]--;

					if (indeg[t] == 0 && !done[t]) {
						Q.push(t);
					}
				}
			}
		}
	}

	rep(i, ans.size()) cout << ans[i] << endl;

	return 0;
}
