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

LL N,K;
LL A[200000],F[200000];
 
LL ans = 0;

void solve(){
	LL A_sum = 0;
	for(int i=0;i<N;i++) A_sum += A[i];
	if(A_sum<=K){
		ans = 0;
		return;
	}

	sort(A,A+N,greater<LL>());
	sort(F,F+N);
	vector<LL> AF(N,0);
	for(int i=0;i<N;i++) AF[i] = A[i]*F[i];

	//二部探索でチーム全体の成績を最大どこまで下げられるか見る
	//(今回に関しては低い方がいい)
	LL left = 0;//ギリギリいけるライン
	LL right = *max_element(AF.begin(),AF.end())+1;//ギリギリ無理なライン
	while(left+1<right){
		LL center = (left+right)/2;//このcenterが狙う最小値なのかどうかを調べる

		auto ok = [&](){
			LL sum = 0;//成績をcenterにするのに必要な修行の総量
			for(int i=0;i<N;i++){
				LL diff = AF[i]-center;
				if(diff>0) sum += (diff/F[i] + (diff%F[i]!=0));
			}
			return sum<=K;
		};

		if(ok()) right = center;//修行の総量がK以下だったならばもっとcenterを下げる
		else left = center;
	}

	ans = right;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) cin >> F[i];
 
    solve();
 
    cout << ans << endl;
    return 0;
}