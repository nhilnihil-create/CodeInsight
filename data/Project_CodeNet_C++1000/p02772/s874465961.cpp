#include <bits/stdc++.h>

int main(void)
{
	int N;
	std::cin >> N;

	std::vector<int> a;
	for (int i = 0; i < N; i++) {
		int num;
		std::cin >> num;

		if (num % 2 == 0)
			a.push_back(num);
	}

	int cnt = 0;

	for (int i : a) {
		if ((i%3 == 0) || (i%5 == 0) )
			cnt++;
	}

	if (cnt == a.size())
		std::cout << "APPROVED" << std::endl;
	else
		std::cout << "DENIED" << std::endl;
}