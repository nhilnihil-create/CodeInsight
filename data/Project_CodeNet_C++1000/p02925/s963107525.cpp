
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;


const int BIG_INT = 1000000000;

const int MAX_N = 1005;
const int MAX_V = MAX_N * (MAX_N - 1) / 2;

vector<int> to[MAX_V];
int id[MAX_N][MAX_N];

int toId(int i,int j) {
	if (i > j) {
		swap(i, j);
	}
	return id[i][j];
}
int dp[MAX_V];
bool visited[MAX_V];
bool calculated[MAX_V];

int dfs(int v) {
	
	if (visited[v]) {
		
		if (!calculated[v]) {
			
			return -1;
		}

		return dp[v];
	}

	visited[v] = true;
	dp[v] = 1;
	for (int u: to[v]) {
		int res = dfs(u);
		if (res == -1) {
			return -1;
		}
		dp[v] = max(dp[v], res + 1);
	}

	calculated[v] = true;
	
	return dp[v]; 
}

int main(){
	int n;
	cin >> n;

	vector<vector<int>> a(n,vector<int>(n-1));
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n - 1; j++) {
			cin >> a[i][j];
			a[i][j]--;

		}
	}
	int v = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				id[i][j] = v;
				v++;
			}
		}
	}


	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n-1; j++) {
			a[i][j] = toId(i, a[i][j]);
		}

		for (int j = 0; j < n - 2; j++) {
			to[a[i][j+1]].emplace_back(a[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < v; i++) {
		int res = dfs(i);
		if (res == -1) {
			cout << -1 << endl;
			return 0;
		}
		ans = max(ans, res);
	}

	cout << ans << endl;

	return 0;
}  

