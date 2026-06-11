#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main(){

	int num,E,from,to,table[10000],tmp;
	vector<int> V[10000];
	queue<int> Q;

	for(int i = 0; i < 10000; i++)table[i] = 0;

	scanf("%d %d",&num,&E);

	for(int i = 0; i < E; i++){
		scanf("%d %d",&from,&to);
		V[from].push_back(to);
		table[to]++;
	}

	for(int i = 0; i < num; i++){
		if(table[i] == 0){
			Q.push(i);
		}
	}

	while(!Q.empty()){
		tmp = Q.front();
		Q.pop();
		printf("%d\n",tmp);
		for(int i = 0; i < V[tmp].size(); i++){
			table[V[tmp][i]]--;
			if(table[V[tmp][i]] == 0){
				Q.push(V[tmp][i]);
			}
		}
	}

	return 0;
}