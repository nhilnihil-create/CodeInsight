#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;

vector<int> v[100005];
ll MOD = 1000000007;


/*
  このノードに既に色が割り当てられている場合の、子孫ノードの色の割り当て方を返す
*/
ll dfs( int node, int parent_node ){
	
	// 子ノードの色の割り当て方
	// 親ノード・このノード のどちらとも重複しない塗り方は何通りか？
	ll available_colors = K - 1 - (parent_node == -1 ? 0 : 1); // 利用可能な色
	ll comb = 1; // 組み合わせ
	for ( size_t i = 0; i < v[node].size(); i++ ){
		int next_node = v[node][i];
		if ( next_node == parent_node )
			continue;
		
		comb = (comb * available_colors--) % MOD;
	}
	
	// 孫ノードの色の割り当て方
	for ( size_t i = 0; i < v[node].size(); i++ ){
		int next_node = v[node][i];
		if ( next_node == parent_node )
			continue;
		
		comb = (comb * dfs( next_node, node )) % MOD;
	}
	//cout << node << " " << comb << endl;
	return comb;
}



int main(){
	cin >> N >> K;
	
	for ( int i = 0; i < N-1; i++ ){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	ll result = (K * dfs( 0, -1 ))%MOD;
	cout << result << endl;
	
	
	return 0;
}

