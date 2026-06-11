/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>

#define rep(i, n) for(int i = 0; i < n; i++)
 
//const long long INF = 1LL << 60;
const int INF = 1e9;
using ll = long long;

int main()
{
	int N;
	std::cin >> N;
	std::priority_queue<double, std::vector<double>, std::greater<double>> v;
	rep(i, N)
	{
		double tmp;
		std::cin >> tmp;
		v.push(tmp);
	}

	while(true)
	{
		double a, b;
		a = v.top();
		v.pop();
		b = v.top();
		v.pop();
		v.push((a + b) / 2);

		if(v.size() == 1)
		{
			break;
		}
	}

	std::cout << v.top() << std::endl;

	return 0;
}