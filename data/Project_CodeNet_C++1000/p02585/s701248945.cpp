//g++ -std=c++14 test.cpp -o test.out

//ポイント：「商を決める→あまりを決める」でダメなら順序を変えて、「あまりを決める→商を決める」にしてみる
 
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
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,K;
LL P[5001],C[5001];

LL ans = -INF;

void solve(){
	//点iから行って戻ってくるまでにかかる操作回数
	vector<LL> loop(N+1);
	//点iから行って戻ってくるまでに稼げるスコア
	//もし負なら0としておく
	vector<LL> score_per_loop(N+1);
	for(int i=1;i<=N;i++){
		LL score = 0;
		LL point = i;
		LL numof_loop = 0;
		while(1){
			point = P[point];
			score += C[point];
			numof_loop++;
			if(i==point) break;
		}
		loop[i] = numof_loop;
		score_per_loop[i] = max(0LL,score);
	}

	for(int i=1;i<=N;i++){
		//各点iから初めて、0~K回操作を行った時のスコアの最大値を求める
		LL point = i;
		LL score = 0;
		for(int operation=1;operation<=min(K,loop[i]);operation++){
			point = P[point];
			score += C[point];
			ans = max(ans,score + max(0LL,((K-operation)/loop[i]))*score_per_loop[i]);
		}
	}
}
 
int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++) cin >> P[i];
	for(int i=1;i<=N;i++) cin >> C[i];
 
    solve();

    cout << ans << endl;
    return 0;
}