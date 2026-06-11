#include <bits/stdc++.h>
using namespace std;

/** defines and macros */
#define ll long long
#define ull unsigned long long
#define loop(n) for(int i = 0; i < n; i++)
#define loop1(n) for(int i = 1; i <= n; i++)
#define all(v) ((v).begin()), ((v).end())
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vvi vector<vi>
#define vvpii vector<vii>
#define PB push_back

#define fw(fileName) freopen(fileName, "w", stdout)
#define fr(fileName) freopen(fileName, "r", stdin)
#define fc(stream) fclose(stream);

#define faster_IO_stream ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

/*To compile and run

	g++ -o main main.cpp && ./main

*/

/*
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣀⣤⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣀⡀⠄⠄⠄⠄⠄⣰⣷⡀⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⣀⣀⣀⠄⠄⠄⠄⠄⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⠄⠄⢠⣿⣿⣷⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠤⠒⠛⠛⠛⠛⠻⠷⣦⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⣿⣿⣿⠟⠁⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⢀⣤⣤⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣡⡤⠐⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⢀⣶⣿⣿⠿⢛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⢠⣿⠟⠉⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠘⠁⠄⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠻⣿⣿⣿⣿⣿⣿⣿⡛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⣾⣿⡿⣽⡿⢹⣿⣿⣟⣿⢻⠇⢀⢹⣿⢿⣿⣿⣿⣿⣿⣦⣙⢿⣿⢷⣈⠻⢿⣟⢿⣿⣿⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⢿⡿⠁⡿⠁⢸⣿⣿⢹⡇⢸⠄⠈⠄⠻⣏⠻⣿⡿⣿⣿⣿⣌⠛⢿⡌⠙⢧⣀⠙⢳⡹⢻⣿⣿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠘⡇⠄⡇⢠⣼⣿⣿⠈⡇⠘⠤⠤⠤⠤⢜⣢⣘⡻⢮⡛⢿⣿⣷⣬⡤⠤⠤⠤⠥⠤⠥⢬⣿⣧⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠁⠄⠄⠘⢿⡏⠛⠄⠄⠄⠄⠄⠄⠄⠄⠄⠙⣿⣿⣿⡿⠋⠉⠛⠉⠄⠄⠄⠄⠄⠄⠄⢹⡿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠘⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡟⠁⠈⢳⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠱⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⡜⠁⠄⠄⠈⢇⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠑⠦⢄⣀⣀⣀⣀⣀⠴⠊⠄⠄⠄⠄⠄⠄⠑⠤⢀⣀⣀⣀⡀⠠⠔⠋⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣶⣦⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣤⣶⣆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⣿⣿⣿⣿⣶⣄⣀⣀⣀⣀⣤⣾⣿⣿⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⣿⣿⣿⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠘⣿⣿⣿⣿⠟⠁⠄⠄⠄⠄⠙⢿⣿⣿⣿⡟⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠘⠟⠋⠁⠄⠄⠄⠄⠄⠄⠄⠄⠉⠛⠿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
 */

//const int MAXN = 100;
//int graph[MAXN][MAXN];
//int visited[MAXN];


int dfs(const vvi &graph, vi &visited, int vertix)
{
	int c = 1;
	visited[vertix] = 1;
	for(int child: graph[vertix]) if(!visited[child]) c += dfs(graph, visited, child);
	return c;
}

int main() {
	faster_IO_stream

	int n, m;
	cin >> n >> m;

	vvi graph(n + 1); vi visited(n + 1);

	int v1, v2;
	loop(m) {
		cin >> v1 >> v2;
		graph[v1].PB(v2);
		graph[v2].PB(v1);
	}

	int res = -1;
	loop1(n)
		if(!visited[i]) res = max(res, dfs(graph, visited, i));
	cout << res << endl;

	return 0;
}
