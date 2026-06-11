#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

vector<vector<int>>g;
vector<bool>visited;
vector<int>tp;

void dfs(int v){
	visited[v]=true;
	for(auto x:g[v]){
		if(visited[x])continue;
		dfs(x);
	}
	tp.pb(v);
}
void solve(){
	int v,e;
	cin>>v>>e;
	g.resize(v);
	visited.resize(v,false);
	rep(i,e){
		int s,t;
		cin>>s>>t;
		g[s].pb(t);
	}
	rep(i,v){
		if(visited[i])continue;
		dfs(i);
	}
	reverse(tp.begin(),tp.end());//逆順にするのを忘れない
	for(auto x:tp){
		cout<<x<<endl;
	}
	return ;
}

signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}

