#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#define INF long long (int)1e18+1
#define MAX 200001
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;
	
vector<int>M[100001];
int main() {
	int n, m;
	cin >> n >> m;
	int x, y;
	vector<bool>isDone(n + 1, 0);
	int ans = 0;
	rep(i, 0, m) {
		cin >> x >> y;
		M[x].push_back(y);
		M[y].push_back(x);
	}
	rep(i, 1, n+1) {
		if (isDone[i])continue;
		isDone[i] = true;
		//cout << i << endl;
		ans++;
		int now;
		queue<int>que;
		for (auto a : M[i]) {
			if (isDone[a])continue;
			que.push(a);
			isDone[a] = true;
		}
		while (!que.empty()) {
			now = que.front();
			for (auto a : M[now]) {
				if (isDone[a])continue;
				que.push(a);
				isDone[a] = true;
			}
			que.pop();
		}
	}
	cout << ans - 1 << endl;
}
