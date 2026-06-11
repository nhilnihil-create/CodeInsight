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

LL N,K;
LL A[500];

LL ans = 1;

void solve(){
	LL A_sum = 0;
	for(int i=0;i<N;i++){
		A_sum += A[i];
	}

	//A_sumの約数について一つづつ見ていく
	//約数は高々√(N*max(A)個しかない
	set<LL> divisor;
	for(LL i=1;i*i<=A_sum;i++){
		if(A_sum%i==0){
			divisor.insert(i);
			divisor.insert(A_sum/i);
		}
	}
	for(LL x:divisor){
		LL need;//操作の必要回数
		{
			//calc need
			vector<LL> r(N);
			for(int i=0;i<N;i++) r[i] = A[i]%x;
			sort(r.begin(),r.end());

			//rの要素をいくつかデクリメントして0にし
			//残りをインクリメントしてxの倍数にすることを考えると
			//rのうち小さいものをデクリメントし
			//大きいものをインクリメントすると
			//少ない処理回数で条件を満たせそうというのがわかる
			LL B = 0;
			for(int i=0;i<N;i++) B+=(x-r[i]);

			LL A = 0;
			need = 1e18;//操作の必要回数
			for(int i=0;i<N;i++){
				A += r[i];//デクリメント回数
				B -= (x-r[i]);//インクリメント回数
				if(A==B) need = min(need,A);
			}
		}
		if(need<=K) ans = max(ans,x);
	}
}
 
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++) cin >> A[i];
 
	solve();
 
	cout << ans;
	return 0;
}