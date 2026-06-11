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
	int N;
	std::cin >> N;
	std::vector<int> d(N);
	rep(i, N)	std::cin >> d[i];
	
	std::sort( d.begin(), d.end() );

	// 1:存在するか?
	int mid = d.size() / 2;
	mid--;	// index 
	bool isOk = false;
	if( d[mid] != d[mid+1] )
	{
		isOk = true;
	}

	// 2:何通りあるか?
	int ans = d[mid+1] - d[mid];

	if( isOk == true )
	{
		std::cout << ans << std::endl;
	}
	else
	{
		std::cout << 0 << std::endl;
	}
	
    return 0;
}
