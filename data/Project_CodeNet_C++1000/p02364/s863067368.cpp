#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
/*union-find*/
const int MAX_V =100010;
int parent[MAX_V];//parent[x]=xの時xが根である
int rank[MAX_V];
struct edge
{
	int u,v,cost;
	edge(int _u,int _v,int _cost){
		u =_u;
		v =_v;
		cost =_cost;
	}
};
void init(int V){
	for(int i= 0;i < V;i++){
		parent[i] = i;
		rank[i] =0;
	}
}

int find(int x){
	if(parent[x] == x)
		return x;
	else{
		return find(parent[x]);
	}
}

void unit(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y)
		return;
	if(rank[x] < rank[y]){
		parent[x] = y;
	}
	else{
		parent[y] = x;
		if(rank[x] == rank[y])
			rank[x]++;
	}
}

bool same(int x,int y){
	return find(x) == find(y);
}
//コストが低い順にsortする
bool cmp(const edge &left,const edge &right){
	return left.cost <right.cost;
}
vector<edge> es;

int V,E;
int kruskal(){
	init(V);
	sort(es.begin(),es.end(),cmp);
	int res = 0;
	for(int i =0;i <E;i++){
		edge e =es[i];
		if(!same(e.u,e.v)){
			unit(e.u,e.v);
			res +=e.cost;
		}
	}
	return res;
}


int main(){
	cin>>V>>E;
	for(int i =0;i < E;i++){
		int u,v,cost;
		cin>>u>>v>>cost;
		es.push_back(edge(u,v,cost));
	}
	
	cout <<kruskal()<<endl;
	return 0;
}