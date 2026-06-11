#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 10000;

vector<int> G[MAX_N];
int color[MAX_N];
deque<int> L;
bool flag;	//????????????

void visit(int u)
{
	if(color[u] == 0){
		flag = true;	//DAG??§??????
		return;
	}
	if(color[u] == 1){
		return;
	}
	color[u] = 0;
	for(int i=0;i<G[u].size();i++){
		visit(G[u][i]);
	}
	color[u] = 1;
	L.push_front(u);
}

int main()
{
	int n;
	int m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	for(int i=0;i<n;i++){
		color[i] = -1;
	}
	for(int i=0;i<n;i++){
		if(color[i] == -1){
			flag = false;
			visit(i);
		}
		if(flag == true){
			break;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d\n",L[i]);
	}
}