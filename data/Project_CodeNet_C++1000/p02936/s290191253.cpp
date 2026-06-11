/*
ID: anonymo14
TASK: wormhole
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;

#define F first
#define S second
#define PU push
#define PUF push_front
#define PUB push_back
#define PO pop
#define POF pop_front
#define POB pop_back
#define REP(i,a,b) for(int i=a; i<=b; i++)
#define MOD 1000000007

void bfs(vector<bool> &vis, vector<vector<int>> &v, vi &sum) {
	queue<pair<int,int>> q;
	q.PU({0,0});
	while(!q.empty()) {
		pair<int,int> p = q.front();
		q.PO();
		if(!vis[p.F]) {
			vis[p.F]=1;
			sum[p.F]+=p.S;
			for(auto i:v[p.F]) q.PU({i, sum[p.F]});
		}
	}
}

void solve(int test_case) {//209
	int n,q;
	cin>>n>>q;
	vector<vector<int>> v(n, vi());
	REP(i,1,n-1) {
		int a,b;
		cin>>a>>b;
		a--;b--;
		v[a].PUB(b);
		v[b].PUB(a);
	}
	vi sum(n,0);
	while(q--) {
		int p,x;
		cin>>p>>x;
		p--;
		sum[p]+=x;
	}
	vector<bool> vis(n, 0);
	bfs(vis, v, sum);
	REP(i,0,n-1)cout<<sum[i]<<" ";
}

int main() {
	
	////// FILE BASED IO////
	//freopen("wormhole.in", "r", stdin);
	//freopen("wormhole.out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
