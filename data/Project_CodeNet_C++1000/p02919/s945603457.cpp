//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc140/tasks/abc140_e
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
int P[100000];
 
LL ans = 0;
 
void solve(){
	//入力が順列なので次のような記録の仕方ができる
	//iの位置（インデックス）をidx[i]とおく
	vector<int> idx(N);
	set<int> s;
	for(int i=0;i<N;i++) idx[P[i]] = i;
	//Pは1~Nの順列　Pが大きい順に調べていく
	for(int x=N-1;x>=0;x--){
		int i = idx[x];//P[i] = x
		LL c = 0;

		//今xがいる場所のイテレータを取得
		s.insert(i);
		//left[0] = 左に進んで1個目の赤丸（赤丸については動画参照）
		//left[1] = 左に進んで2個目の赤丸
		vector<int> left(2,-1);//-1で存在しないことを表すとする
		//right[0] = 右に進んで1個目の赤丸
		//right[1] = 右に進んで2個目の赤丸
		vector<int> right(2,N);//Nで存在しないことを表すとする

		{
			//leftを計算
			auto it = s.find(i);
			for(int j=0;j<2;j++){
				if(it==s.begin()) break;//begin=先頭の要素
				it--;//イテレータを1個戻す
				left[j] = *it;//
			}
		}
		{
			//rightを計算
			auto it = s.find(i);
			for(int j=0;j<2;j++){
				it++;//イテレータを1個戻す
				if(it==s.end()) break;//end=末尾の要素+1
				right[j] = *it;//
			}
		}

		vector<int> ls(2);
		ls[0] = i-left[0]; ls[1] = left[0]-left[1];
		vector<int> rs(2);
		rs[0] = right[0]-i; rs[1] = right[1]-right[0];

		c = (LL)ls[0]*rs[1] + (LL)ls[1]*rs[0];

		ans += c*(x+1);
	}
}
 
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> P[i];
		P[i]--;
	}
 
	solve();
 
	cout << ans << endl;
	return 0;
}