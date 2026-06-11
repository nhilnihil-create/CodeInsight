//g++ -std=c++14 test.cpp -o test.out
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6;
const LL mod = 1000000007ll;

int N,K;
vector<vector<int>> adj_list;//隣接リスト
 
LL ans = 1;
 
void solve(){
	//BFS

	//点iにおける、点0から見た深さ、iにおいて使用不可な色の数を
	//pair<現在の深さ,使用不可な色の数>
	//の形にしておく
	vector<pair<int,int>> point_state(N,make_pair(-1,-1));
	queue<int> q;
	q.push(0);
	point_state[0] = make_pair(0,0);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		int counter = 0;
		for(auto u : adj_list[now]){
			if(point_state[u].first>=0) continue;
			q.push(u);
			point_state[u].first = point_state[now].first + 1;
			if(point_state[u].first<=2){
				point_state[u].second = point_state[u].first + counter;
			}else{
				point_state[u].second = 2 + counter;
			}
			counter++;
		}
	}
	for(int i=0;i<N;i++){
		ans *= (K-point_state[i].second)%mod;
		ans %= mod;
	}
}
 
int main(){
	cin >> N >> K;
	adj_list = vector<vector<int>>(N,vector<int>(0));
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
 
	solve();
 
	cout << ans << endl;
	return 0;
}