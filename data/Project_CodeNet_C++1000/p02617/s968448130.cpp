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
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}
 

int main(){
	//問題文は理解できないが，
	//fは　Sが何個の木で構成されてるかっぽい
	// ⇒ f = (Sの頂点数) - (Sの辺の数) (∵ 木は閉路がない) 
	//そのため，求める答えΣΣfは
	//   ΣΣf = ΣΣ(Sの頂点数) - ΣΣ(Sの辺の数)  かな

	ll N;// Nを計算に使うんでllにしときます
	cin >> N;
	//vec[i]: 頂点iの辺の先のの頂点の列(頂点iとくっついている頂点達)
	//今回はiより小さい頂点は格納しないことにする
	vector<vector<int>> vec(N, vector<int>());
	for(int i=0; i<N-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		// vec[u].push_back(v);
		// vec[v].push_back(u);
		if(u<v) vec[u].push_back(v);
		else vec[v].push_back(u);
	}
	// vertex: 頂点, edge: 辺
	// num_vertex: ΣΣ(Sの頂点数), num_edge: ΣΣ(Sの辺の数)
	ll num_vertex = 0, num_edge = 0;
	for(int i=1; i<=N; i++){
		num_vertex += i*(N-i+1);
		//例 N=3のとき　 num_vertex = 1*3 + 2*2 + 3*1
		//N=4のとき num_vertex = 1*4 + 2*3 + 3*2 + 4*1
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<vec[i].size(); j++){
			num_edge += (i+1) * (N-1 - vec[i][j] +1);
		// LとRを ΣΣで　0~N-1までずらしていくとき 
		//　頂点iと頂点vec[i][j]を結ぶ辺が何回使われるかを数える
		// 例: 頂点2と頂点5を結ぶ辺の場合 
		//     Lの候補は0,1,2 Rの候補は5,6,...,N-1
		// Lの候補とRの候補はそれぞれ独立しているので 
		//  (2+1)  *  {(N-1)-5 + 1} 
		}
	}
	//cout << " num_vertex: " << num_vertex << " num_edge: " << num_edge << endl; 
	ll ans = num_vertex - num_edge;
	cout << ans << endl;

}
