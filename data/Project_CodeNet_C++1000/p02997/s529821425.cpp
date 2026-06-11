#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef long double ld;


int main(){
	int n, k; cin >> n >> k;
	vector<pair<int, int>> edges;
	for(int i = 1; i<=n; i++){
		for(int j = i+1; j<=n; j++) edges.push_back({i, j});
	}
	int cnt = 0;
	while(cnt<k && edges.back().first != 1) edges.pop_back(), cnt++;
	if (cnt == k){
		printf("%d\n", int(edges.size()));
		for(auto e: edges) printf("%d %d\n", e.first, e.second);
	}
	else puts("-1");
	return 0;
}
