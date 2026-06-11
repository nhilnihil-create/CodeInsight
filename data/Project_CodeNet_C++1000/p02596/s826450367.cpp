/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

#define rep(i, n) for(int i=0; i < n; i++)

const long long INF = 1LL << 60;

int main()
{
	int K;
	std::cin >> K;
 
	std::vector<int> checker( 1000001, -1 );
 
	// 1回目は決め打ち	ほかの項と出し方が違うので
	checker[1] = 7 % K;
 
	// 1周してしまうまではすべて別の数が出てくる。出てくる数の種類は最大でもK-1種類なので、
	// K回目まで行けば必ず1週する
	for( int cntup = 2; cntup <= K; cntup++ )
	{
		checker[cntup] = ( checker[cntup-1] * 10 + 7 ) % K;	// mod前を保持するとすぐオーバーフローする 
		//printf( "%d:%d\n", cntup, checker[cntup] );
	}
 
	rep( ans, 1000001 )
	{
		if( checker[ans] == 0 )
		{
			std::cout << ans << std::endl;
			return 0;
		}
		else
		{
			continue;
		}
	}
 
	std::cout << -1 << std::endl;
 
    return 0;
}
