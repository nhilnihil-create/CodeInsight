//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc131/tasks/abc131_e
//この手の構築を安定して解くためには
//まず典型的なグラフたちに対して
//「最短経路長が 2 となる組数はどうなってるか」を観察する
//パス（一本の長いやつ）
//スターグラフ (ウニみたいなあれ)
//完全グラフ（全部繋がってるやつ）
//完全二部グラフ
//パスにちょっとヒゲを生やしたグラフ
//などなど。

//まず、頂点がN個ある時
//頂点同士の組の個数はN(N-1)/2
//さらに、N個の頂点から連結グラフ
//(少なくとも単独で点が存在しない状態)
//を作るためには
//N-1本の辺が必要

//頂点同士の組の個数はN*(N-1)/2で、
//このうち少なくともN-1組に関しては最短距離が
//1となる。
//よってこの時、最短距離が2となるような組の個数は
//最大でもN(N-1)/2 - (N-1) = (N-1)(N-2)/2個となる

//これを達成できるグラフにはスターがある
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

int ans = -1;
vector<pair<int,int>> ans_edge;
 
void solve(){
	int mx = (N-1)*(N-2)/2;//最短距離が2となるような点の組の数の最大値
	if(mx<K){//これより大きくは絶対ならない
		return;
	}

	//ansにスターを構築
	for(int i=1;i<=N-1;i++){
		ans_edge.push_back(make_pair(N,i));
	}
	//スターの葉（外周の点）に対し辺を作って
	//最短距離が2となる組を潰していく
	int add = mx-K;//追加する辺の数（潰す組の数）

	//潰す辺の候補 スターの葉同士をつなぐ辺を列挙しておく
	vector<pair<int,int>> edge;
	for(int i=1;i<=N-1;i++){
		for(int j=1;j<i;j++){
			edge.push_back(make_pair(i,j));
		}
	}
	for(int i=0;i<add;i++) ans_edge.push_back(edge[i]);
	ans = ans_edge.size();
}
 
int main(){
	cin >> N >> K;
 
	solve();
 
	cout << ans << endl;
	for(int i=0;i<ans_edge.size();i++){
		cout << ans_edge[i].first << " " << ans_edge[i].second << endl;
	}
	return 0;
}