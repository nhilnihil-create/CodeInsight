#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int>P;
#define PI 3.14159265359
#define MOD 1000000007
const int MAX =510000;
vector<vector<P>>G(100001);//行先と辺番号を記す
int N;
vector<int>res(100001); 

//v 頂点　ｐ親　ｐｃおやとの辺の色、色のメモ
void dfs(int v,int p,int pc,vector<int>&res){
	int color=1;
	if(color==pc)color++;
	for(auto e:G[v]){
    	if(e.first==p)continue;
      	res[e.second]=color;
      	dfs(e.first,v,color,res);
      	color++;//次の頂点の色をかえる
      	if(pc==color)color++;//ダブりがないよう数字を定める。
    }
  
}


int main(){
	cin >>N;
  	rep(i,N-1){
    	int a,b;
    	cin >>a>>b;
    	G[a].push_back(P(b,i));
    	G[b].push_back(P(a,i));
    }
  	int maxcolor=0;
  	rep(i,N){maxcolor=max(maxcolor,(int)G[i].size());}
  	dfs(1,-1,-1,res);
  	cout<<maxcolor<<endl;
  	for(int i=0;i<N-1;i++){cout<<res[i]<<endl;}
  
  
}
