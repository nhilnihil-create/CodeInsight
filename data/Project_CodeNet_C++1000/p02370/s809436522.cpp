#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<bool> vb;
typedef vector<vp> vvp;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const double pi=acos(-1);
const double eps=1e-8;

class Graph{
	private:
	int GV,GE;
	vvi List;
	void TSfunc(int v,vb& used){
		used[v]=1;
		for(int i=0;i<List[v].size();i++){
			int u=List[v][i];
			if(!used[u]) TSfunc(u,used);
		}
		ts.push_back(v);
	}
	public:
	vi ts;
	Graph(int v,int e){
		GV=v;
		GE=e;
		List=vvi(v);
	}
	void add_edge(int x,int y){
		List[x].push_back(y);
	}
	void TS(){
		vb used(GV);
		for(int i=0;i<GV;i++){
			if(!used[i]) TSfunc(i,used);
		}
	}
};

int V,E;

int main(){
	cin>>V>>E;
	Graph gra(V,E);
	int s,t;
	for(int i=0;i<E;i++){
		cin>>s>>t;
		gra.add_edge(s,t);
	}
	gra.TS();
	for(int i=V-1;i>=0;i--) cout<<gra.ts[i]<<endl;
}