#include<iostream>
#include<vector>

int main()
{
	int H, W;
	while (1) {
		std::cin >> H >> W;
		std::vector<int> v1(H);
		std::vector<int> v2(W);
		if (H == 0 && W == 0)break;
		for (auto i = v1.begin(); i != v1.end(); i++) {
			for (auto j = v2.begin(); j != v2.end(); j++) {
				std::cout << '#';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}