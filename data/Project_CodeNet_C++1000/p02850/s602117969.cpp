#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 100005

struct Edge{
	Edge(int arg_to,int arg_index){
		to = arg_to;
		index = arg_index;
	}
	int to,index;
};

int N;
int K;
vector<Edge> G[SIZE];
int ans[SIZE];

void dfs(int node_id,int pre_node,int pre_color){

	int tmp = 0;


	for(int i = 0; i < G[node_id].size(); i++){

		int child = G[node_id][i].to;
		if(child == pre_node)continue;

		int index = G[node_id][i].index;

		tmp++;
		if(tmp == pre_color)tmp++;

		K = max(K,tmp);

		ans[index] = tmp;
		dfs(child,node_id,tmp);
	}
}


int main(){

	scanf("%d",&N);

	int from,to;

	for(int i = 0; i < N-1; i++){

		scanf("%d %d",&from,&to);
		from--;
		to--;

		G[from].push_back(Edge(to,i));
		G[to].push_back(Edge(from,i));
	}

	K = 0;

	dfs(0,-1,-1);

	printf("%d\n",K);

	for(int i = 0; i < N-1; i++){

		printf("%d\n",ans[i]);
	}

	return 0;
}
