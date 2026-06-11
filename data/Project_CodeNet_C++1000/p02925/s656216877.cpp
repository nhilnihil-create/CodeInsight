#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 1005



int N;
int table[SIZE][SIZE];
int loc[SIZE];


bool check(int node_id){

	if(loc[node_id] == N-1)return false;

	int next = table[node_id][loc[node_id]];

	if(loc[next] == N-1)return false;

	return table[next][loc[next]] == node_id;
}


int main(){

	scanf("%d",&N);

	for(int i = 0; i < N; i++){
		for(int k = 0; k < N-1; k++){

			scanf("%d",&table[i][k]);
			table[i][k]--;
		}
	}

	for(int i = 0; i < N; i++){

		loc[i] = 0;
	}

	int CURRENT = 0,NEXT = 1;

	vector<pair<int,int>> V[2];

	for(int i = 0; i < N; i++){
		if(check(i)){

			int next = table[i][loc[i]];
			V[CURRENT].push_back(make_pair(min(i,next),max(i,next)));
		}
	}

	int ans = -1;

	for(int day = 1; ;day++){

		if(V[CURRENT].size() == 0)break;
		ans = day;

		sort(V[CURRENT].begin(),V[CURRENT].end());
		V[CURRENT].erase(unique(V[CURRENT].begin(),V[CURRENT].end()),V[CURRENT].end());

		for(int i = 0; i < V[CURRENT].size(); i++){

			int a = V[CURRENT][i].first;
			int b = V[CURRENT][i].second;

			loc[a]++;
			loc[b]++;

			if(check(a)){
				int next = table[a][loc[a]];
				V[NEXT].push_back(make_pair(min(a,next),max(a,next)));
			}
			if(check(b)){
				int next = table[b][loc[b]];
				V[NEXT].push_back(make_pair(min(b,next),max(b,next)));
			}
		}
		V[CURRENT].clear();
		swap(CURRENT,NEXT);
	}

	for(int i = 0; i < N; i++){
		if(loc[i] != N-1){

			printf("-1\n");
			return 0;
		}
	}

	printf("%d\n",ans);

	return 0;
}
