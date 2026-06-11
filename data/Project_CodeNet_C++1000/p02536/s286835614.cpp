#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int n,m,cnt;
vector<int> g[MAXN] ;
bool used[MAXN] ;
vector<int> comp ;

void dfs(int v) {
    used[v] = true ;
    comp.push_back(v);
    for (size_t i = 0; i < (int) g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

void find_comps() {
    for (int i = 0; i < n ; ++i)
        used [i] = false;
    for (int i = 0; i < n ; ++i)
        if (!used[i]) {
            comp.clear();
            dfs(i);
            cnt++;
           /* cout << "Component:" ;
            for (size_t j = 0; j < comp.size(); ++j)
                cout << ' ' << comp[j];
            cout << endl ;*/
        }
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	find_comps();
	printf("%d\n", cnt-1);
	return 0;
}