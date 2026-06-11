#include <bits/stdc++.h>

// red + blue
// = (all_xor ^ blue) + blue
// = (all_xor ^ blue) ^ blue + ((all_xor ^ blue) & blue) * 2
// = all_xor + ((all_xor & blue) ^ blue) * 2
//
// {1, 0} => 0
// {1, 1} => 0
// {0, 0} => 0
// {0, 1} => 1
int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int64_t> A(N);
	for (auto& e: A) scanf("%lld", &e);
	int64_t all_xor{};
	for (auto& e: A) all_xor ^= e;
	// all_xorが立ってればblueの総^が立つようなblueの選び方
	for (int row{60}, col{}; row >= 0 && col < N; row--)
	{
		if (all_xor >> row & 1) continue;
		for (int i{col}; i < N; i++)
			if (A[i] >> row & 1)
			{
				std::swap(A[col], A[i]);
				break;
			}
		if (~A[col] >> row & 1) continue;
		for (int i{}; i < N; i++)
			if (i != col && (A[i] >> row & 1))
				A[i] ^= A[col];
		col++;
	}
	int64_t blue{};
	for (auto& e: A) blue ^= e;
	printf("%lld\n", all_xor + 2 * ((all_xor & blue) ^ blue));

	return 0;
}