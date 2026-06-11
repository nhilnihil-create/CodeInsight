#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX_N = 100000;

int par[MAX_N];
int depth[MAX_N];
vector<int> to[MAX_N];
vector<int> from[MAX_N];

int main()
{
	int t,index,n,m,prev;
	string s;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&index);
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&t);
			to[index].push_back(t);
			from[t].push_back(index);
		}
	}
	for(int i=0;i<n;i++){
		if(from[i].empty() == true){
			par[i] = -1;
		}else{
			par[i] = *(from[i].begin());
		}
	}
	fill(depth,depth+n,0);
	for(int i=0;i<n;i++){
		prev = par[i];
		while(prev != -1){
			prev = par[prev];
			depth[i]++;
		}
	}
	for(int i=0;i<n;i++){
		if(par[i] == -1){
			s = "root";
		}else if(to[i].empty() == true){
			s = "leaf";
		}else{
			s = "internal node";
		}
		printf("node %d: parent = %d, depth = %d, ",i,par[i],depth[i]);
		cout << s << ", [";
		vector<int>::iterator it = to[i].begin();
		if(it != to[i].end()){
			printf("%d",*it);
			it++;
		}
		while(it != to[i].end()){
			printf(", %d",*it);
			it++;
		}
		printf("]\n");
	}
}