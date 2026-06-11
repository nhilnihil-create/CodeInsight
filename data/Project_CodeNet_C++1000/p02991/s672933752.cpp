#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



ll N, M;

vector<int> next_node[100000];

int main(){
	cin >> N >> M;
	
	for ( int i = 0; i < M; i++ ){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		next_node[u].push_back(v);
	}
	
	int S, T;
	cin >> S >> T;
	S--;
	T--;
	
	queue<pair<int,int>> q;
	map<int,bool> visit[3]; // 到達予定なら、印をつける
	
	q.push({S,0});
	while ( !q.empty() ){
		auto a = q.front();
		q.pop();
		int node = a.first;
		int step = a.second;
		
		if ( step % 3 == 0 ){
			if ( node == T ){
				cout << step/3 << endl;
				return 0;
			}
		}
		
		step++;
		for ( auto it : next_node[node] ){
			if ( visit[step%3][it] )
				continue;
			visit[step%3][it] = true;
			q.push({it,step});
		}
	}
	
	cout << -1 << endl;
	return 0;
}

