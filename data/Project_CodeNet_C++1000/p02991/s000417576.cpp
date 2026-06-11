//g++ -std=c++14 test.cpp -o test.out
//URL
//https://atcoder.jp/contests/abc142/tasks/abc142_e
//BFSは重みなしグラフの、スタート地点Sから各頂点の最短距離を求められる
//重みがあったらダイクストラを使う必要が出てくる
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
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647;
const LL mod = 1000000007ll;
 
int N,M;
vector<vector<int>> to;//iから行くことのできる点の集合をto[i]とする
int S,T;
 
int ans = 0;
 
void solve(){
	vector<vector<int>> distance(N,vector<int>(3,INF_INT));
	//Sから頂点uへの距離をdとしたとき、uへd%3でいけるような経路が存在するなら
	//distance[u][d%3] = dとする
	//いけないならdistance[u][d%3] = INF
	queue<pair<int,int>> q;//pair<頂点番号,長さのmod>
	q.push(make_pair(S,0));
	distance[S][0] = 0;//Sはスタート地点の頂点　スタート地点からSまでの距離は当然0で、0%3=0なのでこうなる
	//BFS
	while(!q.empty()){
		int v = q.front().first;//頂点番号
		int l = q.front().second;//長さのmod
		q.pop();
		for(int u : to[v]){
			int next_l = (l+1)%3;
			if(distance[u][next_l]!=INF_INT) continue;//Sからuへいく経路で、その長さ%3がiであるような経路をもう見つけたならば
			distance[u][next_l] = distance[v][l]+1;
			q.push(make_pair(u,next_l));
		}
	}
	ans = distance[T][0];
	if(ans==INF_INT) ans=-1;
	else ans/=3;
}
 
int main(){
	cin >> N >> M;
	to = vector<vector<int>>(N);
	for(int i=0;i<M;i++){
		int u,v;
		cin >> u >> v;
		to[u-1].push_back(v-1);
	}
	cin >> S >> T;
	S--;T--;
 
	solve();
 
	cout << ans << endl;
	return 0;
}