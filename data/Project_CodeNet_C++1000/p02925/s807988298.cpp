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
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
vector<queue<LL>> battle;
LL numof_empty_of_battle = 0;//battleのうち、emptyなキューの数
 
LL ans = 0;

void solve(){
	//対戦そのものを型として持つキュー
	queue<pair<LL,LL>> battle_day;
	//選手iが対戦可能かを返す 可能なら対戦相手を返す
	auto is_ready = [&](LL i){
		LL enemy = battle[i].front();
		if(battle[enemy].empty()) return -1LL;
		if(battle[enemy].front()==i) return enemy;
		return -1LL;
	};
	//まず1日目にどんな試合があるかについて見ていく
	vector<int> reserved(N+1,0);
	for(int i=1;i<=N;i++){
		//選手iがもうすでに試合決定しているかどうかをreserved[i]とする
		if(reserved[i]) continue;
		LL enemy = is_ready(i);
		if(enemy>0 && !reserved[enemy]){
			battle_day.push(pair<LL,LL>(i,enemy));
			reserved[i] = 1;
			reserved[enemy] = 1;
		}
	}
	//day日目について見ていき、
	//キューにある今日の試合の処理ー＞翌日の試合をキューへ
	//といったことをする
	for(int day=1;;day++){
		//前日にひとつも試合を用意できていない時
		if(battle_day.empty()){
			if(numof_empty_of_battle==battle.size()-1){
				ans = day-1;
				if(!ans) ans = -1;
				return;
			}
			else{
				ans = -1;
				return;
			}
		}
		//キューにある試合を全部見にいく
		queue<pair<LL,LL>> prev_battle_day;//今回処理した試合を格納
		//cout << "\nbattle_day:" << endl;
		while(!battle_day.empty()){
			pair<LL,LL> fight = battle_day.front();battle_day.pop();
			prev_battle_day.push(fight);
			//printf("%lld vs %lld\n",fight.first,fight.second);

			battle[fight.first].pop();
			if(battle[fight.first].empty()) numof_empty_of_battle++;

			battle[fight.second].pop();
			if(battle[fight.second].empty()) numof_empty_of_battle++;
		}
		// for(int a=0;a<battle.size();a++){
		// 	printf("battle[%d].size()=%d\n",a,(int)battle[a].size());
		// }
		//翌日の試合のペアをそれぞれ1つづつ見た時、どれも必ず今日の試合に出た人を含む
		//よって今日の試合に出た人をprev_battle_dayから調べていく

		//選手iがもうすでに試合決定しているかどうかをreserved[i]とする
		vector<int> reserved(N+1,0);
		while(!prev_battle_day.empty()){
			pair<LL,LL> fight = prev_battle_day.front();prev_battle_day.pop();

			LL first_enemy = is_ready(fight.first);
			if(first_enemy>0 && !reserved[first_enemy] && !reserved[fight.first]){
				reserved[fight.first] = 1;
				reserved[first_enemy] = 1;
				battle_day.push(pair<LL,LL>(fight.first,first_enemy));
			}

			LL second_enemy = is_ready(fight.second);
			if(second_enemy>0 && !reserved[second_enemy] && !reserved[fight.second]){
				reserved[fight.second] = 1;
				reserved[second_enemy] = 1;
				battle_day.push(pair<LL,LL>(fight.second,second_enemy));
			}
		}
	}
}

int main(){
    cin >> N;
    battle = vector<queue<LL>>(N+1);
    for(int i=1;i<=N;i++){
    	for(int j=0;j<N-1;j++){
    		LL x;
    		cin >> x;
    		battle[i].push(x);
    	}
    }
 
    solve();
 
    cout << ans << endl;
    return 0;
}