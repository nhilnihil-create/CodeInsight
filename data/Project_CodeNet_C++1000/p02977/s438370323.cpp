#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

int main()
{
	LL N;
	in >> N;

	LL _ = N;
	while (N % 2 == 0) N /= 2;
	if (N == 1)
	{
		out << "No" << std::endl;
		return 0;
	}
	N = _;

	std::vector<std::pair<LL, LL>>ans;
	ans.push_back({ 1,2 });
	ans.push_back({ 2,3 });
	ans.push_back({ 3,1 + N });
	ans.push_back({ 1 + N,2 + N });
	ans.push_back({ 2 + N,3 + N });
	for (LL i = 4; i < N; i += 2)
	{
		ans.push_back({ i,i + 1 });
		ans.push_back({ i + 1,1 + N });
		ans.push_back({ 1 + N,i + N });
		ans.push_back({ i + N,i + 1 + N });
	}
	if (N % 2 == 0)
	{
		ans.push_back({ N,N - 1 });
		ans.push_back({ ((N - 1) ^ 1 ^ N) + N,2 * N });
	}

	out << "Yes" << std::endl;
	rep(i, ans.size()) out << ans[i].first << " " << ans[i].second << std::endl;
}
