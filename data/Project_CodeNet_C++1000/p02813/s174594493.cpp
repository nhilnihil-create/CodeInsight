#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> P(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> P[i];
	}
	std::vector<int> Q(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> Q[i];
	}

	int all = 1;
	for (int i = N; i > 1; --i) {
		all *= i;
	}

	int order_P = 0;
	{
		int remain = all;

		std::vector<int> arr(N);
		for (int i = 0; i < N; ++i) {
			arr[i] = i + 1;
		}

		for (int i = 0; i < N; ++i) {
			int index = 1;
			for (auto itr = arr.begin(); itr != arr.end(); ++itr,++index) {
				if (P[i] == *itr) {
					remain /= (int)arr.size();
					order_P += remain*(index - 1);
					arr.erase(itr);
					break;
				}
			}
		}
	}

	int order_Q = 0;
	{
		int remain = all;

		std::vector<int> arr(N);
		for (int i = 0; i < N; ++i) {
			arr[i] = i + 1;
		}

		for (int i = 0; i < N; ++i) {
			int index = 1;
			for (auto itr = arr.begin(); itr != arr.end(); ++itr, ++index) {
				if (Q[i] == *itr) {
					remain /= (int)arr.size();
					order_Q += remain * (index - 1);
					arr.erase(itr);
					break;
				}
			}
		}
	}

	if (order_P >= order_Q) {
		std::cout << order_P - order_Q << std::endl;
	}
	else
	{
		std::cout << order_Q - order_P << std::endl;

	}
	return 0;
}