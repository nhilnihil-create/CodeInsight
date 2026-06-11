#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<long long> A;
	std::vector<long long> B;
	int N = 0, M = 0, K = 0;

	std::cin >> N >> M >> K;;

	A.resize(N + 1);
	B.resize(M + 1);

	int readingTime = 0;

	// A.at(index)にはindex冊目までの合計時間を記録する
	for (size_t index = 1; index < A.size(); ++index)
	{
		std::cin >> readingTime;
		A.at(index) = A.at(index - 1) + readingTime;
	}

	// B.at(index)もAと同様
	for (size_t index = 1; index < B.size(); ++index)
	{
		std::cin >> readingTime;
		B.at(index) = B.at(index - 1) + readingTime;
	}

	// 答えを表す変数answer
	size_t answer = 0;

	// Aを0番目のコンテナからKを超える値があるコンテナの直前まで走査する。
	// B.at(j) <= K - A.at(index)が成り立つような整数jの最大値を探す。
	// index + j の最大値が求める値となる。
	for (size_t index = 0; index < A.size(); ++index)
	{
		if (A.at(index) > K)
		{
			break;
		}

		while (B.at(M) > K - A.at(index))
		{
			--M;
		}

		answer = std::max(answer, index + M);
	}
	
	std::cout << answer << std::endl;
}