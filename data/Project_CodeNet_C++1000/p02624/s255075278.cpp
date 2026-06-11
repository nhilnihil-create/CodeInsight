#include <iostream>

int main()
{
	// 数字Nを読み込む。
	int N = 0;
	std::cin >> N;

	// 計算する。計算方法を変える。任意のn∈[1, N]についてN以下のnの倍数を調べ、等差数列の和を調べる。
	long long answer = 0;

	for (int index = 1; index <= N; ++index)
	{
		long long n = N / index;
		answer += n * (n + 1) * index / 2;
	}

	// 答えを出力する。
	std::cout << answer << std::endl;
}