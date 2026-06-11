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
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const LL mod = 1000000007ll;

LL N,K;
LL A[200000];

LL ans = 0;

LL S[200001];//累積和
//S[0] = 0
//S[i] = A[0] ~ A[i-1]の和　(i>=1)
//と決める
//A[0] = S[1] - S[0]
//......
//A[i] = S[i+1] - S[i]
//......
//A[N-1] = S[N] - S[N-1]

//A[i] + A[i+1] + A[i+2] + .... + A[j-2] + A[j-1] = S[j] - S[i]
//A[i] ~ A[j-1]は要素数j-i

//j>iの時
//(S[j]-S[i])%K==(j-i) 
//つまり
//(S[j]−j)%K==(S[i]−i)%K かつ (j−i)<K
//となるようなi,jの組の数を求める
void solve(){
	S[0] = 0;
	for(int i=1;i<=N;i++) S[i] = (S[i-1] + A[i-1])%K;
	for(int i=0;i<=N;i++) S[i] = (S[i] + (K-i%K))%K;

	//現在見ているインデックスがiだとしたとき、
	map<LL,LL> mp;//S[i-(K-1)]~S[i]のうち、Kで割ったあまりがS[i]である数の個数をmp[S[i]]とおく
	queue<LL> q;//S[i-(K-1)]~S[i]を格納する
	for(int i=0;i<=N;i++){
		ans += mp[S[i]];
		mp[S[i]]++;
		q.push(S[i]);
		while(q.size()>=K){
			mp[q.front()]--;//q.front()はS[i-(K-1)]~S[i]から外れてしまうので減らす
			q.pop();
		}
	}
}
 
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> A[i];
		A[i] = A[i]%K;
	}
 
	solve();

	cout << ans << endl;
	return 0;
}