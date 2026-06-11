//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc036/tasks/agc036_a
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

LL S;

LL ans[6];//(X1,Y1),(X2,Y2),(X3,Y3)の順

void solve(){
	//原点を固定
	ans[0] = ans[1] = 0;
	//三角形の面積*2 = Y2*X3 - X2*Y3

	//S = 10^9*X3 - Y3
	//と固定してしまっても残りのX3,Y3で
	//1<=S<=10^18の全てを表現可能

	//さらにこれはSを10^9で割った商とあまりを使えば表せる

	ans[2] = 1;//X2 = 1に固定
	ans[3] = 1e9;//Y2 = 10^9に固定

	ans[4] = S/1e9;//X3
	ans[5] = S%((LL)1e9);//Y3

	if(ans[5]!=0){
		ans[4]++;
		ans[5] = 1e9 - ans[5];
	}
}
 
int main(){
	cin >> S;
 
	solve();
 
	for(int i=0;i<6;i++) cout << ans[i] << " ";
	return 0;
}