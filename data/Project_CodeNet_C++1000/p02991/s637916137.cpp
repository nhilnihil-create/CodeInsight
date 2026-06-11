#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

struct Info{
	Info(int arg_node_id,int arg_step,int arg_sum_dist){
		node_id = arg_node_id;
		step = arg_step;
		sum_dist = arg_sum_dist;
	}
	bool operator<(const struct Info &arg) const{

		return sum_dist > arg.sum_dist; //総距離の降順(PQ)
	}

	int node_id,step,sum_dist;
};


int N,M;
int min_dist[SIZE][4];
int start,goal;
vector<int> G[SIZE];


int main(){

	scanf("%d %d",&N,&M);

	int from,to;

	for(int i = 0; i < M; i++){

		scanf("%d %d",&from,&to);
		from--;
		to--;

		G[from].push_back(to);
	}

	scanf("%d %d",&start,&goal);
	start--;
	goal--;

	for(int i = 0; i < N; i++){
		for(int k = 1; k <= 3; k++){

			min_dist[i][k] = BIG_NUM;
		}
	}

	priority_queue<Info> Q;
	min_dist[start][3] = 0;

	Q.push(Info(start,3,0));

	while(!Q.empty()){

		if(Q.top().sum_dist > min_dist[Q.top().node_id][Q.top().step]){

			Q.pop();

		}else{

			for(int i = 0; i < G[Q.top().node_id].size(); i++){

				int next = G[Q.top().node_id][i];
				int next_step = Q.top().step+1;
				int next_dist = Q.top().sum_dist;

				if(next_step == 4){

					next_step = 1;
					next_dist++;
				}

				if(min_dist[next][next_step] > next_dist){

					min_dist[next][next_step] = next_dist;
					Q.push(Info(next,next_step,next_dist));
				}
			}

			Q.pop();
		}
	}

	if(min_dist[goal][3] == BIG_NUM){

		printf("-1\n");

	}else{

		printf("%d\n",min_dist[goal][3]);
	}

	return 0;
}
