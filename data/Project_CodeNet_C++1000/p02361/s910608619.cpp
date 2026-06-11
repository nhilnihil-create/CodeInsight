
#include<cstdio>
#include<queue>
#include<vector>
#include<utility>

const int INF=999999999;

typedef std::pair<int,int> path_t;//first->node second->cost

struct nodes{
		int cost,num;
		std::vector<path_t> path;
		bool visited=false;
};
bool operator>(const nodes node_a,const nodes node_b){
		return node_a.cost>node_b.cost;
}
std::priority_queue<nodes,std::vector<nodes>,std::greater<nodes> > pq;

int v,e,r;
nodes node[100000];

void initialize(void){
	for(int lp=0;lp<100000;lp++){
		node[lp].cost=INF;
		node[lp].num=lp;
	}
}

void input(void){
	int s,t,d;
	scanf("%d%d%d",&v,&e,&r);
	for(int lp=0;lp<e;lp++){
		scanf("%d%d%d",&s,&t,&d);
		node[s].path.push_back(std::make_pair(t,d));
	}
}
void solve(void){
	node[r].cost=0;
	node[r].visited=true;
	pq.push(node[r]);
	while(!pq.empty()){
		nodes node_now=pq.top();
		pq.pop();
		for(int lp=0;lp<(int)node_now.path.size();lp++){
			int nextcost=node_now.path[lp].second+node_now.cost;
			int nextnode=node_now.path[lp].first;
			//printf("nownode:%d nowcost:%d nextnode:%d nextcost:%d\n",node_now.num,node_now.cost,nextnode,nextcost);
			if(node[nextnode].visited==false && nextcost<node[nextnode].cost){
				node[nextnode].cost=nextcost;
				pq.push(node[nextnode]);
			}
		}
	}
}

void output(void){
	for(int lp=0;lp<v;lp++){
		if(node[lp].cost==INF){
			printf("INF\n");
		}else{
			printf("%d\n",node[lp].cost);
		}
	}
}

int main(void){
	initialize();
	input();
	solve();
	output();
	return 0;
}


