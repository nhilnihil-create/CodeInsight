#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<25;
const double pi=acos(-1);
const double eps=1e-8;
const vi emp;

class Graph{
	private:
	int V,E;
	public:
	vvi Pro;
	void add_V(int v){
		V=v;
		Pro=vvi(V,vi(V,inf));
		for(int i=0;i<V;i++) Pro[i][i]=0;
	}
	void add_edge(int x,int y,int c){
		Pro[x][y]=c;
		Pro[y][x]=c;
	}
	void WARSALL(){
		for(int k=0;k<V;k++) for(int i=0;i<V;i++) for(int j=0;j<V;j++) Pro[i][j]=min(Pro[i][j],Pro[i][k]+Pro[k][j]);
	}
};

int V=-1,E;

int main(){
	while(1){
		cin>>E;
		if(!E) break;
		V=0;
		Graph gra;
		vi S,T,C;
		int s,t,c;
		for(int i=0;i<E;i++){
			cin>>s>>t>>c;
			S.push_back(s);
			T.push_back(t);
			C.push_back(c);
			V=max(V,max(s,t));
		}
		V++;
		gra.add_V(V);
		for(int i=0;i<E;i++) gra.add_edge(S[i],T[i],C[i]);
		gra.WARSALL();
		P ans(-1,inf);
		for(int i=0;i<V;i++){
			int sum=0;
			for(int j=0;j<V;j++) sum+=gra.Pro[i][j];
			if(sum<ans.second) ans=P(i,sum);
		}
		cout<<ans.first<<' '<<ans.second<<endl;
	}
}