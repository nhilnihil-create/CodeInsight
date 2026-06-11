#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;
typedef struct data{int node,time;}data;
int cmp(void const *a,void const *b){
	return ((data*)a)->time < ((data*)b)->time;
}
int time = 0;
int visited[10001];
data a[10001];
vector<int> vec[10001];
int dfs(int x){
	if(visited[x]==1){
		return 0;
	}
	else{
		int i;
		visited[x]=1;
		for(i=0;i<vec[x].size();i++){
			dfs(vec[x][i]);
		}
		a[x].node = x;
		a[x].time = time++;
	}
}
int main(){
	int n,m,u,v,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
	}
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	for(i=0;i<n;i++){
		dfs(i);
	}
	qsort(a,n,sizeof(data),cmp);
	for(i=0;i<n;i++){
		printf("%d\n",a[i].node);
	}
	return 0;
}