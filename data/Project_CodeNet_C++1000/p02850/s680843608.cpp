#include<cstdio>
#include <vector>
#include<utility>
#include <stack>
#include<algorithm>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	int a[N-1], b[N-1];
	vector<pair<int, int> > edge[N];
	for (int i = 0; i < N-1; ++i){
		scanf("%d %d", a+i, b+i);
		a[i]--;b[i]--;
		edge[a[i]].push_back(make_pair(b[i], i));
		edge[b[i]].push_back(make_pair(a[i], i));
	}
	int color[N], kinshi[N], K = 0;
	kinshi[0] = 0;
	bool has_been_discovered[N];
	has_been_discovered[0] = true;
	for (int i = 1; i < N; ++i){
		has_been_discovered[i] = false;
	}
	stack<int> S;
	S.push(0);
	while(!S.empty()){
		int u = S.top(); S.pop();
		int clr_this = 1;
		for (int i = 0; i < edge[u].size(); ++i){
			int v = edge[u][i].first;
			if(!has_been_discovered[v]){
				has_been_discovered[v] = true;
				S.push(v);
				kinshi[v] = color[edge[u][i].second] = clr_this == kinshi[u] ? ++clr_this : clr_this;
				if(clr_this > K) K = clr_this;
				clr_this++;
			}
		}
	}
	printf("%d\n", K);
	for (int i = 0; i < N-1; ++i){
		printf("%d\n", color[i]);
	}
	return 0;
}