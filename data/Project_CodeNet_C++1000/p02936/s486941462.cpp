#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);


long long N, Q;
vector<LL> P;
vector<LL> ANS;

void dfs(Graph &G, LL v, LL parent, vector<LL> &done){
	if(done[v] == 1) return;

	for(auto next_v : G[v]){
		if(next_v != parent){
			ANS[next_v] += ANS[v];
			dfs(G, next_v, v, done);
		}
	}
	done[v] = 1;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> Q;
	Graph G(N);
	P.assign(N, 0);
	ANS.assign(N, 0);
	for(int i=0; i<N-1; i++){
		int a, b;
		cin >> a >> b;
		G[a - 1].push_back(b - 1);
		G[b - 1].push_back(a - 1);
	}

	for(int i=0; i<Q; i++){
		LL p, x;
		cin >> p >> x;
		P[p - 1] += x;
	}
	for(int i=0; i<N; i++){
		ANS[i] = P[i];
	}

	vector<LL> done;
	done.assign(N, 0);
	dfs(G, 0, 0, done);

	for(int i=0; i<N; i++){
		printf("%lld", ANS[i]);
		if(i < N - 1) printf(" ");
	}
	printf("\n");
	return 0;
}