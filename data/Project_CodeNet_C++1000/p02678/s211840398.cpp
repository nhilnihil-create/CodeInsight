#include <bits/stdc++.h>

/*                    ॐ Shree ॐ                     */
/* ॐ ॐ ॐ
ॐ भूर् भुवः स्वः
तत् सवितुर्वरेण्यं
भर्गो देवस्य धीमहि
धियो यो नः प्रचोदयात्
*/
using namespace std;
typedef long long int ll;
int a, b, n, m, test;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
// online submission
#endif

	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	bool flag=false;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		if(a==1||b==1){
			flag=true;
		}
	}

	queue<int> q;
	vector<bool> visited(n + 1, false);
	vector<int> len(n + 1, INT_MAX);
	len[1] = 0;
	q.push(1);
	while (!q.empty()) {

		visited[q.front()] = true;
		for (int i :v[q.front()]) {
			if (!visited[i]) {
			
				len[i] = q.front();
				visited[i] = true;
				q.push(i);
			}
		}

		q.pop();
	}
	for (int i = 2; i <= n; i++) {
		if(len[i]==INT_MAX){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes\n";
	for (int i = 2; i <= n; i++) {
		cout << len[i] << "\n";
	}

}