//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc139/tasks/abc139_e
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
const int INF_INT = 2147483647;
const LL mod = 1000000007ll;
 
int N;
vector<vector<int>> A;//選手iがj番目に戦う相手をA[i][j]とおく
 
int ans = 0;
 
void solve(){
	vector<pair<int,int>> q;//試合を格納するキュー
	//vectorをキューのように扱ってみる
	//工夫次第でqueueより制約は強いが追加、消去がO(1)でできる
	auto check = [&](int i){//選手iが試合できるかを調べて、できるならキューに格納
		//A[i](i番目の選手が戦う相手の集合)が空ならそもそも試合できないのでreturn
		if(A[i].size()==0) return;
		int j = A[i].back();//iの対戦相手をjとおく
		if(A[j].back()==i){//jの次の相手がiなら
			pair<int,int> fight(i,j);
			if(fight.second<fight.first) swap(fight.first,fight.second);
			q.push_back(fight);
		}
	};
	for(int i=0;i<N;i++){
		check(i);
	}
	while(q.size()>0){
		ans++;
		//vectorにおける重複要素の除去方法
		//まずソート
		sort(q.begin(),q.end());
		//それからerase関数を呼び出す　これで重複が削除できる
		q.erase(unique(q.begin(),q.end()),q.end());
		vector<pair<int,int>> prevQ;
		swap(prevQ,q);
		for(auto p : prevQ){
			int i = p.first;
			int j = p.second;
			A[i].pop_back();//A[i]の末尾の要素を削除
			A[j].pop_back();
		}
		for(auto p : prevQ){
			int i = p.first;
			int j = p.second;
			check(i);
			check(j);
		}
	}
	//リストが全部からになってたら日数を出力
	for(int i=0;i<N;i++){
		if(A[i].size()!=0){
			ans = -1;
			return;
		}
	}
}
 
int main(){
	cin >> N;
	A = vector<vector<int>>(N,vector<int>(N-1));
	for(int i=0;i<N;i++){
		for(int j=0;j<N-1;j++){
			cin >> A[i][j];
			A[i][j]--;//選手の番号を0始まりにする
		}
		//vectorは先頭からの消去は遅く、末尾からの消去は早い
		//このためあらかじめ配列を逆向きにしておく
		reverse(A[i].begin(),A[i].end());
	}
 
	solve();
 
	cout << ans << endl;
	return 0;
}