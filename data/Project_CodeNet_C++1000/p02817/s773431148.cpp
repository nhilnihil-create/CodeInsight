#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int,int>;
using Graph = vector<vector<int>>;

const int N = 100005;
vector<pair<int, ll> > g[N];
ll dist[N];
 
void dfs(int v, int p){
	for(auto x : g[v]){
		if(x.first == p)continue;
		dist[x.first] = dist[v] + x.second;
		dfs(x.first, v);
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);
 
	string s, t; 
    cin >> s >> t;
    cout << t+s << "\n";
	return 0;
}