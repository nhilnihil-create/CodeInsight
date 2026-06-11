#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl;
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   " << endl;
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}
 
int main(){
	int N, X, Y;
	cin >> N >> X >> Y;
	X--; Y--;

	//ダイクストラ法で解いてみる
	typedef pair<int, int> P;
	//vec[i]: ノードiと隣接してるノードと辺のコストの列
	vector<vector<P>> vec(N, vector<P>());
	
	for(int i=0; i<N-1; i++){
		vec[i].push_back(P(i+1, 1));//今回のコストはすべて1
		vec[i+1].push_back(P(i, 1));
	}
	vec[X].push_back(P(Y, 1));
	vec[Y].push_back(P(X, 1));
	vector<ll> ans(N+1, 0);//ans[k]:手数kかかる組み合わせ
	const ll MAX = 1001001001;
	for(int s=0; s<N; s++){
		vector<ll> cost(N, MAX);//ノードsからの最小手数
		queue<P> q;// first:注目ノード, second:注目ノードの親
		q.push(P(s, -1));
		cost[s] = 0;
		while(!q.empty()){
			int node = q.front().first;
			int parent = q.front().second;
			q.pop();
			for(int j=0; j<vec[node].size(); j++){
				int child = vec[node][j].first;
				int yen = vec[node][j].second;
				//if(child == parent) continue;
				if(cost[child] <= cost[node]+yen) continue;
				cost[child] = cost[node]+yen;
				q.push(P(child, node));
			}
		}
		for(int i=0; i<cost.size(); i++){
			ans[cost[i]]++;
		}

	}
	for(int i=1; i<=N-1; i++){
		cout << ans[i]/2 << endl;
	}

	// //BFS解法
	// //vec[i]: ノードiと隣接してるノードの列
	// vector<vector<ll>> vec(N, vector<ll>());
	// for(int i=0; i<N-1; i++){
	// 	vec[i].push_back(i+1);
	// 	vec[i+1].push_back(i);
	// }
	// vec[X].push_back(Y);
	// vec[Y].push_back(X);
	// //cout << " vec:" << endl; print_vec2(vec);
	// vector<ll> ans(N+1, 0);//ans[k]:手数kかかる組み合わせ
	// typedef pair<int, int> P;
	// for(int s=0; s<N; s++){
	// 	vector<ll> cost(N, -1);//ノードsからの最小手数
	// 	queue<P> q;// first:注目ノード, second:注目ノードの親
	// 	q.push(P(s, -1));
	// 	cost[s] = 0;
	// 	while(!q.empty()){
	// 		int node = q.front().first;
	// 		int parent = q.front().second;
	// 		q.pop();
	// 		for(int j=0; j<vec[node].size(); j++){
	// 			int child = vec[node][j];
	// 			//if(child == parent) continue;//
	// 			if(cost[child] != -1) continue;//
	// 			cost[child] = cost[node] + 1;
	// 			q.push(P(child, node));
	// 		}
	// 		//if(s==0){cout << " cost: "; print_vec(cost);}
	// 	}

	// 	for(int i=0; i<cost.size(); i++){
	// 		ans[cost[i]]++;
	// 	}

	// }
	// for(int i=1; i<=N-1; i++){
	// 	cout << ans[i]/2 << endl;
	// }




	//数学的な解法 //解説PDFの解法
	// vector<ll> ans(N+1, 0);//cnt[k]:歩数kかかる組み合わせ
	// for(int s=0; s<=N-2; s++){
	// 	for(int g=s+1; g<=N-1; g++){
	// 		ll steps1 = g - s;//XYの道を使わない歩数
	// 		ll steps2 = abs(s-X) + 1 + abs(Y-g); //XYの道を使う歩数
	// 		ll mn = (steps1 < steps2) ? steps1 : steps2;
	// 		ans[mn]++;
	// 	}
	// }

	// for(int i=1; i<=N-1; i++){
	// 	cout << ans[i] << endl;
	// }

}
