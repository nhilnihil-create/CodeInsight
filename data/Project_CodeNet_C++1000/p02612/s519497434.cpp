#include<iostream>

int main() {
	int N = {};// 商品代金
	int change={};//お釣り
	int Min_value = 1;//下限値
	int Max_value = 10000;//上限値
	std::cin >> N ;

	if (Min_value > N || N > Max_value) {
		std::cout << "予算を10000円を超えてます！" << std::endl;
	}

	while (N >= 1000)
	{
		if (N == 1000) {
			change = 0;
			std::cout << change << std::endl;
			return 0;
		}

		N=N - 1000;

	}

	change = 1000-N;
	std::cout << change << std::endl;


}