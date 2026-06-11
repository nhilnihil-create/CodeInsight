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
	int N;
	std::cin >> N;

	std::vector<int> A(N);

	std::vector<int> ans(N);
	rep(i, N)
	{
		int id = i + 1;
		int ppl = 0;
		std::cin >> ppl;
		ans[ppl - 1] = id;
	}

	for( int i : ans  )
	{
		std::cout << i << " ";
	}

    return 0;
}
