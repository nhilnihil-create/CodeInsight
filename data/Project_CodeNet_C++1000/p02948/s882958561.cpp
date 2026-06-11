#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

signed main(){
	lint N, M; cin >> N >> M;
	vector<vector<lint> > data(M + 1);
	for(lint i = 0; i < N; i++){
		lint a, b; cin >> a >> b;
		if(a > M) continue;
 		data[a].push_back(b);
	}
	lint ans = 0;
	priority_queue<lint> que;
	for(lint i = 1; i <= M; i++){
		for(lint j = 0; j < data[i].size(); j++) que.push(data[i][j]);
		if(que.size()) ans += que.top(), que.pop();
	}
	cout << ans << endl;
}