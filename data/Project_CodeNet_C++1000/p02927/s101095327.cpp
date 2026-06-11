#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

int main()
{
	LL M, D;
	in >> M >> D;

	LL ans = 0;
	for (LL m = 1; m <= M; ++m)
	{
		for (LL d = 1; d <= D; ++d)
		{
			LL d1 = d % 10, d2 = d / 10;
			if (d1 >= 2 && d2 >= 2 && d1 * d2 == m) ++ans;
		}
	}
	out << ans << std::endl;
}
