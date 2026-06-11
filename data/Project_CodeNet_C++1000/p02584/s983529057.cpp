/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>

#define rep(i, n) for(int i = 0; i < n; i++)

//const long long INF = 1LL << 60;
const int INF = 1e9;
using ll = long long;

int main()
{
	long long X, K, D;
	std::cin >> X >> K >> D;
	X = std::abs( X );	// absするので符号は関係ない わかりやすいので+から引き算する 

	// Y = D * K <-> K = Y / D 
	long long by_0_cnt = std::min( K, X / D );	// K回動くか、X / D(0にたどりつくまでの回数)を得る
	K -= by_0_cnt;
	X -= by_0_cnt * D;

	long long ans = 0;
	if( K % 2 == 0 )
	{
		ans = X;
	}
	else
	{
		ans = D - X;	// 最小まで言っているのでDのほうがXより大きいj
						// 最小まで行ってない場合はK == 0になる 
	}

	std::cout << ans << std::endl;

	return 0;
}
