#include <bits/stdc++.h>

typedef long long ll;

const int N = 1e9;

ll s;

int main()
{
	std::cin >> s; int c = (s + N - 1) / N;
	std::cout << "0 0 " << N << " 1 " << 1ll * N * c - s << " " << c << std::endl;
	return 0;
}