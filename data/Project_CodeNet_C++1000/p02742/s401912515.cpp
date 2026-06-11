#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define rep(i, n) for(int i=0; i < n; i++)

const long long INF = 1LL << 60;

int main()
{
	long long H, W;
	std::cin >> H >> W;
	if((H==1) || (W==1))
	{
		std::cout << 1 << std::endl;
		return 0;
	}
	long long ans = (H * W) / 2;
	if((ans * 2) != (H * W))
	{
		ans++;
	}
	std::cout << ans << std::endl;
	return 0;
}
