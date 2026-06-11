#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B
//if it is not fully connected component
#define N 105
vector<int> nebors[N];//start from 1
int start[N]; // start form 1
int end[N]; //end with 1
int vis_nei[N]; // neighbor
stack<int> s;
int dfs(int k,int d){
	start[k] = (++d);

	for(int i = 0; i<nebors[k].size(); i++){
		int temp = nebors[k].at(i);
		if(start[temp]==-1) d = dfs(temp,d);
	}
	end[k] = (++d);
	return d;
}

int main(){
	int n;
	scanf("%d",&n);
	memset(start,-1,sizeof(start));
	memset(end,-1,sizeof(end));
	memset(vis_nei,-1,sizeof(vis_nei));
	//vis_nei
	for(int i = 1; i<=n; i++){
		int id,num;
		scanf("%d %d",&id, &num);
		for(int j = 0; j<num; j++){
			int temp;
			scanf("%d",&temp);
			nebors[id].push_back(temp);
			//nebors[temp].push_back(id);
		}
	}
	//check each node for the (unfully connected)
	int d = 0;
	for(int i = 1; i<n; i++){
		if(start[i]==-1){
			d = dfs(i,d);
		}
	}
	
	for(int i = 1; i<=n; i++){
		printf("%d %d %d\n",i,start[i],end[i]);
	}
}

