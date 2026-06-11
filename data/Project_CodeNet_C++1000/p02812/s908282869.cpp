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
	std::string S;
	std::cin >> N >> S;
	int count = 0;
	for (int i = 0; i < N - 2; ++i) {
		if ((S[i] == 'A') && (S[i + 1] == 'B') && (S[i + 2] == 'C')) {
			++count;
		}
	}
	std::cout << count << std::endl;

	return 0;
}