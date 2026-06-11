#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<stack>
#include<queue>
#include<sstream>
#include<string>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i);

using namespace std;

struct node{
	int pos;
	int prev;
	double cost;

	node(int t_pos,int t_prev,double t_cost){
		pos = t_pos; prev = t_prev; cost = t_cost;
	}

	bool operator<(const node& a) const { //キューの中身を逆転
		return cost > a.cost;
	}
};

struct root{
	int to;
	double cost;

	root(int t_to,double t_cost){
		to = t_to; cost = t_cost;
	}

};

vector< vector <root> > roots;
int n,m,s,g;

double dp[101][101];

const double INF = 9e9;

void search(){

	fill_n((double *)dp,sizeof(dp)/sizeof(double),INF); //初期化	
	
	priority_queue<node> pq;

	rep(i,roots[s].size()){
	
		root r = roots[s][i];
		
		pq.push( node(r.to,s,r.cost) );
		dp[r.to][s] = r.cost;
	}

	while(!pq.empty()){

		node tn = pq.top();
		pq.pop();

		if( dp[tn.pos][tn.prev] != tn.cost) continue;

		if( tn.pos == g){
			cout << g << " " <<tn.cost << endl;
			return;
		}	

		rep(i,roots[tn.pos].size()){
			root r = roots[tn.pos][i];
			if(r.to == tn.prev) continue;

			for( int j = -1; j< 2; j++){
		//		if( tn.speed + j > 0 && tn.speed +j <= r.speed){
					double cost = tn.cost + r.cost;///(tn.speed+j);
					if( dp[r.to][tn.pos] > cost){
						dp[r.to][tn.pos] = cost;
						pq.push( node( r.to,tn.pos,cost));
					}
				//}
			}
		}
	}

	cout << "unreachable" << endl;
}


int main(){

		cin >> n;

		roots = vector< vector<root> >(n);

    rep(i,n){
      int num,m;
      cin >> num >> m;
      roots[num].push_back( root(num,0));
      rep(j,m){
        int r,cost;
        cin >> r>> cost;
        roots[num].push_back( root(r,cost));
      }
    }
    s=0;
    rep(i,n){
		  g=i;
      search();
    }
}